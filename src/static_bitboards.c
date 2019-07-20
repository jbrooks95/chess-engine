#include <static_bitboards.h>

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

const bitboard RANK_1 = (bitboard) 1 << 56 | (bitboard) 1 << 57 | 
                        (bitboard) 1 << 58 | (bitboard) 1 << 59 | 
                        (bitboard) 1 << 60 | (bitboard) 1 << 61 | 
                        (bitboard) 1 << 62 | (bitboard) 1 << 63;

const bitboard RANK_2 = (bitboard) 1 << 48 | (bitboard) 1 << 49 | 
                        (bitboard) 1 << 50 | (bitboard) 1 << 51 | 
                        (bitboard) 1 << 52 | (bitboard) 1 << 53 | 
                        (bitboard) 1 << 54 | (bitboard) 1 << 55;
                        
const bitboard RANK_3 = (bitboard) 1 << 40 | (bitboard) 1 << 41 | 
                        (bitboard) 1 << 42 | (bitboard) 1 << 43 | 
                        (bitboard) 1 << 44 | (bitboard) 1 << 45 | 
                        (bitboard) 1 << 46 | (bitboard) 1 << 47;
                        
const bitboard RANK_4 = (bitboard) 1 << 32 | (bitboard) 1 << 33 | 
                        (bitboard) 1 << 34 | (bitboard) 1 << 35 | 
                        (bitboard) 1 << 36 | (bitboard) 1 << 37 | 
                        (bitboard) 1 << 38 | (bitboard) 1 << 39;

const bitboard RANK_5 = (bitboard) 1 << 24 | (bitboard) 1 << 25 | 
                        (bitboard) 1 << 26 | (bitboard) 1 << 27 | 
                        (bitboard) 1 << 28 | (bitboard) 1 << 29 | 
                        (bitboard) 1 << 30 | (bitboard) 1 << 31;

const bitboard RANK_6 = (bitboard) 1 << 16 | (bitboard) 1 << 17 | 
                        (bitboard) 1 << 18 | (bitboard) 1 << 19 | 
                        (bitboard) 1 << 20 | (bitboard) 1 << 21 | 
                        (bitboard) 1 << 22 | (bitboard) 1 << 23;

const bitboard RANK_7 = (bitboard) 1 << 8  | (bitboard) 1 << 9  | 
                        (bitboard) 1 << 10 | (bitboard) 1 << 11 | 
                        (bitboard) 1 << 12 | (bitboard) 1 << 13 | 
                        (bitboard) 1 << 14 | (bitboard) 1 << 15;

const bitboard RANK_8 = (bitboard) 1 << 0  | (bitboard) 1 << 1  | 
                        (bitboard) 1 << 2  | (bitboard) 1 << 3  | 
                        (bitboard) 1 << 4  | (bitboard) 1 << 5  | 
                        (bitboard) 1 << 6  | (bitboard) 1 << 7;

const bitboard FILE_A = (bitboard) 1 << 0  | (bitboard) 1 << 8  | 
                        (bitboard) 1 << 16 | (bitboard) 1 << 24 | 
                        (bitboard) 1 << 32 | (bitboard) 1 << 40 | 
                        (bitboard) 1 << 48 | (bitboard) 1 << 56;

const bitboard FILE_B = (bitboard) 1 << 1  | (bitboard) 1 << 9 | 
                        (bitboard) 1 << 17 | (bitboard) 1 << 25 | 
                        (bitboard) 1 << 33 | (bitboard) 1 << 41 | 
                        (bitboard) 1 << 49 | (bitboard) 1 << 57;

const bitboard FILE_C = (bitboard) 1 << 2  | (bitboard) 1 << 10 | 
                        (bitboard) 1 << 18 | (bitboard) 1 << 26 | 
                        (bitboard) 1 << 34 | (bitboard) 1 << 42 | 
                        (bitboard) 1 << 50 | (bitboard) 1 << 58;

const bitboard FILE_D = (bitboard) 1 << 3  | (bitboard) 1 << 11 | 
                        (bitboard) 1 << 19 | (bitboard) 1 << 27 | 
                        (bitboard) 1 << 35 | (bitboard) 1 << 43 | 
                        (bitboard) 1 << 51 | (bitboard) 1 << 59;

const bitboard FILE_E = (bitboard) 1 << 4  | (bitboard) 1 << 12 | 
                        (bitboard) 1 << 20 | (bitboard) 1 << 28 | 
                        (bitboard) 1 << 36 | (bitboard) 1 << 44 | 
                        (bitboard) 1 << 52 | (bitboard) 1 << 60;

const bitboard FILE_F = (bitboard) 1 << 5  | (bitboard) 1 << 13 | 
                        (bitboard) 1 << 21 | (bitboard) 1 << 29 | 
                        (bitboard) 1 << 37 | (bitboard) 1 << 45 | 
                        (bitboard) 1 << 53 | (bitboard) 1 << 61;

const bitboard FILE_G = (bitboard) 1 << 6  | (bitboard) 1 << 14 | 
                        (bitboard) 1 << 22 | (bitboard) 1 << 30 | 
                        (bitboard) 1 << 38 | (bitboard) 1 << 46 | 
                        (bitboard) 1 << 54 | (bitboard) 1 << 62;

const bitboard FILE_H = (bitboard) 1 << 7  | (bitboard) 1 << 15 | 
                        (bitboard) 1 << 23 | (bitboard) 1 << 31 | 
                        (bitboard) 1 << 39 | (bitboard) 1 << 47 | 
                        (bitboard) 1 << 55 | (bitboard) 1 << 63;

const bitboard CENTER = (bitboard) 1 << 27 | (bitboard) 1 << 28 |
                        (bitboard) 1 << 35 | (bitboard) 1 << 36;

const bitboard EXTENDED_CENTER = (bitboard) 1 << 18 | (bitboard) 1 << 19 |
                                 (bitboard) 1 << 20 | (bitboard) 1 << 21 |
                                 (bitboard) 1 << 26 | (bitboard) 1 << 27 |
                                 (bitboard) 1 << 28 | (bitboard) 1 << 29 |
                                 (bitboard) 1 << 34 | (bitboard) 1 << 35 |
                                 (bitboard) 1 << 36 | (bitboard) 1 << 37 |
                                 (bitboard) 1 << 42 | (bitboard) 1 << 43 |
                                 (bitboard) 1 << 44 | (bitboard) 1 << 45;

const bitboard KINGSIDE = (bitboard) 1 << 4  | (bitboard) 1 << 12 |
                          (bitboard) 1 << 20 | (bitboard) 1 << 28 |
                          (bitboard) 1 << 36 | (bitboard) 1 << 44 |
                          (bitboard) 1 << 52 | (bitboard) 1 << 60 |
                          (bitboard) 1 << 5  | (bitboard) 1 << 13 |
                          (bitboard) 1 << 21 | (bitboard) 1 << 29 |
                          (bitboard) 1 << 37 | (bitboard) 1 << 45 |
                          (bitboard) 1 << 53 | (bitboard) 1 << 61 |
                          (bitboard) 1 << 6  | (bitboard) 1 << 14 |
                          (bitboard) 1 << 22 | (bitboard) 1 << 30 |
                          (bitboard) 1 << 38 | (bitboard) 1 << 46 |
                          (bitboard) 1 << 54 | (bitboard) 1 << 62 |
                          (bitboard) 1 << 7  | (bitboard) 1 << 15 |
                          (bitboard) 1 << 23 | (bitboard) 1 << 31 |
                          (bitboard) 1 << 39 | (bitboard) 1 << 47 |
                          (bitboard) 1 << 55 | (bitboard) 1 << 63;

const bitboard QUEENSIDE = (bitboard) 1 << 0  | (bitboard) 1 << 8  | 
                           (bitboard) 1 << 16 | (bitboard) 1 << 24 | 
                           (bitboard) 1 << 32 | (bitboard) 1 << 40 | 
                           (bitboard) 1 << 48 | (bitboard) 1 << 56 |
                           (bitboard) 1 << 1  | (bitboard) 1 << 9  | 
                           (bitboard) 1 << 17 | (bitboard) 1 << 25 | 
                           (bitboard) 1 << 33 | (bitboard) 1 << 41 | 
                           (bitboard) 1 << 49 | (bitboard) 1 << 57 |
                           (bitboard) 1 << 2  | (bitboard) 1 << 10 | 
                           (bitboard) 1 << 18 | (bitboard) 1 << 26 | 
                           (bitboard) 1 << 34 | (bitboard) 1 << 42 | 
                           (bitboard) 1 << 50 | (bitboard) 1 << 58 |
                           (bitboard) 1 << 3  | (bitboard) 1 << 11 | 
                           (bitboard) 1 << 19 | (bitboard) 1 << 27 | 
                           (bitboard) 1 << 35 | (bitboard) 1 << 43 | 
                           (bitboard) 1 << 51 | (bitboard) 1 << 59;
