#include <stdio.h>
#include <stdlib.h>
#include <evaluate.h>
#include <square_control.h>
#include <static_bitboards.h>

// values for each piece
const int K_VAL = 999999999;
const int Q_VAL = 900;
const int B_VAL = 350;
const int N_VAL = 300;
const int R_VAL = 500;
const int P_VAL = 100;
const int CENTER_CONTROL_VAL = 30;
const int EXTENDED_CENTER_CONTROL_VAL = 10;
const int ENEMY_TERRITORY_CONTROL_VAL = 4;
const int DEVELOPMENT_VAL = 30;
const int CASTLE_VAL = 30;
const int PAWN_ADVANCEMENT_VAL = 1;

int evaluate(board* b)
{
    int material = count_material(b);
    int center_control = evaluate_square_control(b);
    int development = evaluate_piece_development(b);
    int king_safety = evaluate_king_safety(b);
    int pawn_structure = evaluate_pawn_structure(b);
    int total = material + center_control + development + king_safety + pawn_structure;
    return total;
}

int count_material(board* b)
{
    int count = 0;
    count += K_VAL*(count_bits(b->white_king) - count_bits(b->black_king));
    count += Q_VAL*(count_bits(b->white_queen) - count_bits(b->black_queen));
    count += B_VAL*(count_bits(b->white_bishops) - count_bits(b->black_bishops));
    count += N_VAL*(count_bits(b->white_knights) - count_bits(b->black_knights));
    count += R_VAL*(count_bits(b->white_rooks) - count_bits(b->black_rooks));
    count += P_VAL*(count_bits(b->white_pawns) - count_bits(b->black_pawns));
    return count;
}

int evaluate_pawn_structure(board* b)
{
    //favor more advanced pawns
    int white_count = 0;
    int black_count = 0;
    int i;
    for(i = 0; i < 63; i++)
    {
        if(RANK_2 >> i & 1)
        {
            white_count += PAWN_ADVANCEMENT_VAL * (0 * (count_bits(b->white_pawns & RANK_2)));
            black_count += PAWN_ADVANCEMENT_VAL * (15 * (count_bits(b->black_pawns & RANK_2)));
        }
        if(RANK_3 >> i & 1)
        {
            white_count += PAWN_ADVANCEMENT_VAL * (1 * (count_bits(b->white_pawns & RANK_3)));
            black_count += PAWN_ADVANCEMENT_VAL * (10 * (count_bits(b->black_pawns & RANK_3)));
        }
        if(RANK_4 >> i & 1)
        {
            white_count += PAWN_ADVANCEMENT_VAL * (3 * (count_bits(b->white_pawns & RANK_4)));
            black_count += PAWN_ADVANCEMENT_VAL * (6 * (count_bits(b->black_pawns & RANK_4)));
        }
        if(RANK_5 >> i & 1)
        {
            white_count += PAWN_ADVANCEMENT_VAL * (6 * (count_bits(b->white_pawns & RANK_5)));
            black_count += PAWN_ADVANCEMENT_VAL * (3 * (count_bits(b->black_pawns & RANK_5)));
        }
        if(RANK_6 >> i & 1)
        {
            white_count += PAWN_ADVANCEMENT_VAL * (10 * (count_bits(b->white_pawns & RANK_6)));
            black_count += PAWN_ADVANCEMENT_VAL * (1 * (count_bits(b->black_pawns & RANK_6)));
        }
        if(RANK_7 >> i & 1)
        {
            white_count += PAWN_ADVANCEMENT_VAL * (15 * (count_bits(b->white_pawns & RANK_7)));
            black_count += PAWN_ADVANCEMENT_VAL * (0 * (count_bits(b->black_pawns & RANK_7)));
        }
    }
    return white_count - black_count;
}

int evaluate_king_safety(board* b)
{
    int white_count = 0;
    int black_count = 0;
    if(b->castling & 4 || b->castling & 8)
    {
        //white hasn't castled
        white_count -= CASTLE_VAL;
    }
    if(b->castling & 1 || b->castling & 2)
    {
        //black hasn't castled
        black_count -= CASTLE_VAL;
    }
    return white_count - black_count;
}

int count_bits(bitboard bb)
{
    int count = 0;
    while(bb > 0)
    {
        if(bb & 1) count++;
        bb>>=1;
    }
    return count;
}

int evaluate_piece_development(board* b)
{
    int white_count = 0;
    white_count += DEVELOPMENT_VAL * count_bits(b->white_knights & ~WHITE_KNIGHTS);
    white_count += DEVELOPMENT_VAL * count_bits(b->white_bishops & ~WHITE_BISHOPS);
    white_count += DEVELOPMENT_VAL * count_bits(b->white_queen & ~WHITE_QUEEN);
    white_count += DEVELOPMENT_VAL * count_bits(b->white_rooks & ~WHITE_ROOKS);
    white_count += DEVELOPMENT_VAL * count_bits(b->white_king & ~WHITE_KING);

    int black_count = 0;
    black_count += DEVELOPMENT_VAL * count_bits(b->black_knights & ~BLACK_KNIGHTS);
    black_count += DEVELOPMENT_VAL * count_bits(b->black_bishops & ~BLACK_BISHOPS);
    black_count += DEVELOPMENT_VAL * count_bits(b->black_queen & ~BLACK_QUEEN);
    black_count += DEVELOPMENT_VAL * count_bits(b->black_rooks & ~BLACK_ROOKS);
    black_count += DEVELOPMENT_VAL * count_bits(b->black_king & ~BLACK_KING);

    return white_count - black_count;
}

int evaluate_square_control(board* b)
{
    int count = 0;
    int white_count = 0;
    int black_count = 0;
    int white_control[64] = {0};
    int black_control[64] = {0};
    get_white_control(b, white_control);
    get_black_control(b, black_control);

    int i;
    for(i = 0; i < 63; i++)
    {
        white_count += white_control[i];
        black_count += black_control[i];
        if(CENTER >> i & 1)
        {
            count += CENTER_CONTROL_VAL*(white_control[i] - black_control[i]);
        }
        if(EXTENDED_CENTER >> i & 1)
        {
            count += EXTENDED_CENTER_CONTROL_VAL*(white_control[i] - black_control[i]);
        }
        if(WHITE_SIDE >> i & 1)
        {
            black_count += ENEMY_TERRITORY_CONTROL_VAL * black_control[i];
        }
        if(BLACK_SIDE >> i & 1)
        {
            white_count += ENEMY_TERRITORY_CONTROL_VAL * white_control[i];
        }
    }
    
    return count + (white_count - black_count);
}
