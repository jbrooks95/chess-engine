#include <stdio.h>
#include <stdlib.h>
#include <evaluate.h>

// values for each piece
const int K_VAL = 999999999;
const int Q_VAL = 900;
const int B_VAL = 350;
const int N_VAL = 300;
const int R_VAL = 500;
const int P_VAL = 100;

int evaluate(board* b)
{
    return count_material(b);
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
