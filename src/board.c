#include <stdio.h>
#include <stdlib.h>
#include <board.h>

board* string_to_board(char* input)
{
    printf("success");
}

void print_board(board* b)
{
    int i, j;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            printf("[");
            printf("%c", get_piece(b, i, j));
            printf("]");
        }
        printf("\n");
    }
}

char get_piece(board* b, int i, int j)
{
    bitboard current_square = get_bitboard(i, j);
    if(b->white_king & current_square) return 'K';
    if(b->white_queen & current_square) return 'Q';
    if(b->white_bishops & current_square) return 'B';
    if(b->white_knights & current_square) return 'N';
    if(b->white_rooks & current_square) return 'R';
    if(b->white_pawns & current_square) return 'P';
    if(b->black_king & current_square) return 'k';
    if(b->black_queen & current_square) return 'q';
    if(b->black_bishops & current_square) return 'b';
    if(b->black_knights & current_square) return 'n';
    if(b->black_rooks & current_square) return 'r';
    if(b->black_pawns & current_square) return 'p';
    return ' '; //square is vacant
}

bitboard get_bitboard(int i, int j)
{
   return ((bitboard)1) << ((i*8) + j);
}

board* init_board(void)
{
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
    board* b = malloc(sizeof(board));
    bitboard start = (bitboard) 1; //cast to bitboard to prevent shift overflow

    b->white_king = start << 60;
    b->white_queen = start << 59;
    b->white_bishops = start << 58 | start << 61;
    b->white_knights = start << 57 | start << 62;
    b->white_rooks = start << 56 | start << 63;
    b->white_pawns = start << 48 |
                     start << 49 |
                     start << 50 |
                     start << 51 |
                     start << 52 |
                     start << 53 |
                     start << 54 |
                     start << 55;

    b->black_king = start << 4;
    b->black_queen = start << 3;
    b->black_bishops = start << 2 | start << 5;
    b->black_knights = start << 1 | start << 6;
    b->black_rooks = start << 0 | start << 7;
    b->black_pawns = start << 8 |
                     start << 9 |
                     start << 10 |
                     start << 11 |
                     start << 12 |
                     start << 13 |
                     start << 14 |
                     start << 15;

    return b;
}
