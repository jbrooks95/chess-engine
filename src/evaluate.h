#ifndef EVAL_H
#define EVAL_H

#include <bitboard.h>
#include <board.h>

/*
 * Evaluates position of given board
 * Returns positive int in
 * favor of white. Negative
 * int in favor of black.
 */
int evaluate(board* b);

/*
 * Returns count of material
 * based on basic piece values.
 * Returns positive int if 
 * white is up material, negative
 * if black is up material.
 */
int count_material(board* b);

/*
 * Returns the number of 
 * set bits
 */
int count_bits(bitboard bb);

int evaluate_square_control(board* b);

int evaluate_piece_development(board* b);

int evaluate_space(board* b);

int evaluate_pawn_structure(board* b);

#endif
