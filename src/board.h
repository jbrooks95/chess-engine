#ifndef BOARD_H
#define BOARD_H

#include <bitboard.h>

typedef struct board 
{
    bitboard white_king;
    bitboard white_queen;
    bitboard white_bishops;
    bitboard white_knights;
    bitboard white_rooks;
    bitboard white_pawns;
    bitboard black_king;
    bitboard black_queen;
    bitboard black_bishops;
    bitboard black_knights;
    bitboard black_rooks;
    bitboard black_pawns;
} board;

//function prototypes

board string_to_board(char* input);

char* board_to_string(board b);

#endif
