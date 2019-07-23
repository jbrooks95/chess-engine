#ifndef SLIDING_H
#define SLIDING_H

#include <static_bitboards.h>
#include <bitboard.h>
#include <board.h>
#include <movelist.h>
#include <shift.h>

/*
 * Add all pseudo-legal sliding moves
 * on a given board to the given list.
 * given a piece.
 */
void slide_straight(move_list* list, board* b, char piece, bitboard origin);
void slide_diagonal(move_list* list, board* b, char piece, bitboard origin);

#endif
