#ifndef BITBOARD_H
#define BITBOARD_H

#include <stdint.h>

typedef uint64_t bitboard;

bitboard start;

void print_bitboard(bitboard b);
int get_index_from_bitboard(bitboard b);

#endif
