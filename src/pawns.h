#ifndef PAWNS_H
#define PAWNS_H

#include <static_bitboards.h>
#include <bitboard.h>
#include <board.h>
#include <movelist.h>
#include <shift.h>

/*
 * Add all pseudo-legal pawn moves
 * on a given board to the given list.
 */
void generate_pawn_moves(move_list*, board* b);

#endif
