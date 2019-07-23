#ifndef SHIFT_H
#define SHIFT_H

#include <bitboard.h>

bitboard shift_left(bitboard b); 
bitboard shift_right(bitboard b); 
bitboard shift_up(bitboard b); 
bitboard shift_up_left(bitboard b); 
bitboard shift_up_right(bitboard b); 
bitboard shift_down(bitboard b); 
bitboard shift_down_left(bitboard b); 
bitboard shift_down_right(bitboard b);

#endif
