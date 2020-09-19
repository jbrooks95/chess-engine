#ifndef SQUARE_CONTROL_H
#define SQUARE_CONTROL_H

#include <bitboard.h>
#include <board.h>


/*
 * Returns an int array representing the number
 * of times a square is controlled by white or black.
 * The return array indices map to a bitboard.
 */
int* get_white_control(board* b, int[]);
int* get_black_control(board* b, int[]);

void print_control_array(int[]);

#endif
