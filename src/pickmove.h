#ifndef PICKMOVE_H
#define PICKMOVE_H

#include <movelist.h>

/*
 * Returns pointer to move determined to be the best
 * given a board and the eval function
 */
move pick_move(board* b, int search_depth);

/*
 * Returns a board with the given move
 * made on the given board. Returns NULL if
 * not a legal move.
 */
board* make_move(board* b, move m);

#endif
