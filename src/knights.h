#ifndef KNIGHTS_H
#define KNIGHTS_H

#include <static_bitboards.h>
#include <bitboard.h>
#include <board.h>
#include <movelist.h>
#include <shift.h>

/*
 * Add all pseudo-legal knight moves
 * on a given board to the given list.
 */
void generate_knight_moves(move_list*, board*);

#endif
