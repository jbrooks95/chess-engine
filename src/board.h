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

board* string_to_board(char* input);

board* init_board(void);

void print_board(board* b);

/*
 * Returns the piece at the given
 * square. Returns space if the
 * square is vacant. Used for representing
 * the board as a string.
 * (0,0) is a8
 * (7,0) is h8
 * (0,7) is a1
 * (7,7) is h1
 */
char get_piece(board* b, int i, int j);

/*
 * Returns the bitboard corresponding
 * to the given coordinates.
 */
bitboard get_bitboard(int i, int j);

#endif
