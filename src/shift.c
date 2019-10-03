#include <shift.h>

/* Grid for shift values:
* [00][01][02][03][04][05][06][07]
* [08][09][10][11][12][13][14][15]
* [16][17][18][19][20][21][22][23]
* [24][25][26][27][28][29][30][31]
* [32][33][34][35][36][37][38][39]
* [40][41][42][43][44][45][46][47]
* [48][49][50][51][52][53][54][55]
* [56][57][58][59][60][61][62][63]
*/

bitboard shift_up(bitboard b) { return b >> 8; }
bitboard shift_down(bitboard b) { return b << 8; }
bitboard shift_left(bitboard b) { return b >> 1; }
bitboard shift_right(bitboard b) { return b << 1; }
bitboard shift_up_left(bitboard b) { return b >> 9; }
bitboard shift_up_right(bitboard b) { return b >> 7; }
bitboard shift_down_left(bitboard b) { return b << 7; }
bitboard shift_down_right(bitboard b) { return b << 9; }

//knight moves
bitboard shift_up_up_left(bitboard b) { return b >> 17; }
bitboard shift_up_up_right(bitboard b) { return b >> 15; }
bitboard shift_up_left_left(bitboard b) { return b >> 10; }
bitboard shift_up_right_right(bitboard b) { return b >> 6; }
bitboard shift_down_down_right(bitboard b) { return b << 17; }
bitboard shift_down_down_left(bitboard b) { return b << 15; }
bitboard shift_down_left_left(bitboard b) { return b << 6; }
bitboard shift_down_right_right(bitboard b) { return b << 10; }
