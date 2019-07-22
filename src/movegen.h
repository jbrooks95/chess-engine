#ifndef MOVEGEN_H
#define MOVEGEN_H

#include <bitboard.h>
#include <board.h>
#include <movelist.h>

/*
 * Returns a list of pseudo-legal moves
 * given a board.
 */
move_list* generate_moves(board* b);

#endif
