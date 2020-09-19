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
const int CENTER_CONTROL_VAL = 20;
const int EXTENDED_CENTER_CONTROL_VAL = 10;

int evaluate(board* b)
{
    int material = count_material(b);
    int center_control = evaluate_center_control(b);
    return material + center_control;
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

int evaluate_center_control(board* b)
{
    int count = 0;
    int white_control[64] = {0};
    int black_control[64] = {0};
    get_white_control(b, white_control);
    get_black_control(b, black_control);

    int i;
    for(i = 0; i < 63; i++)
    {
        if(CENTER >> i & 1)
        {
            count += CENTER_CONTROL_VAL*(white_control[i] - black_control[i]);
        }
        if(EXTENDED_CENTER >> i & 1)
        {
            count += EXTENDED_CENTER_CONTROL_VAL*(white_control[i] - black_control[i]);
        }
    }
    
    return count;
}
