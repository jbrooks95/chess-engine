#ifndef MOVE_H
#define MOVE_H

#include <movelist.h>

/*
 * Returns a board with the given move
 * made on the given board. Returns NULL if
 * not a legal move.
 */
board* make_move(board* b, move m);

/*
 * Returns 1 if the player who just
 * moved king is checked
 */
int is_king_checked(board* b);

#endif
