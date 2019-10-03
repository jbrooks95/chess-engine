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

//knight moves
bitboard shift_up_up_left(bitboard b);
bitboard shift_up_up_right(bitboard b);
bitboard shift_up_left_left(bitboard b);
bitboard shift_up_right_right(bitboard b);
bitboard shift_down_down_right(bitboard b);
bitboard shift_down_down_left(bitboard b);
bitboard shift_down_left_left(bitboard b);
bitboard shift_down_right_right(bitboard b);

#endif
