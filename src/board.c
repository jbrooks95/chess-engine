#include <stdio.h>
#include <stdlib.h>
#include <board.h>
#include <ctype.h>

int to_move = 0; // 0 if white to move, 1 if black to move
int en_passant = -1; // shift value of the target en passant square if exists
int castling = 0xF; // 4-bit binary value that maps to FEN KQkq
int halfmove_clock = 0; // count of halfmoves since last capture or pawn advance
int fullmove_count = 1; // starts at 1, increments after black's move

board* parse_fen(char* fen)
{
    board* b = malloc(sizeof(board));

    // parse piece locations
    int shift_value = 0; 
    int i = 0;
    char current_char = fen[0];
    while(current_char != ' ')
    {
        if(current_char != '/')
        {
            if(isalpha(current_char))
            {
                insert_piece(b, current_char, shift_value);
                shift_value++;
            }
            else if(isdigit(current_char))
            {
                int shift_increase = (int) current_char - 48; // subtract 48 because of ascii
                shift_value += shift_increase;
            }
            else
            {
                fprintf(stderr, "Error: Invalid FEN format");
                return NULL;
            }
        }
        current_char = fen[++i];
    }
    current_char = fen[++i]; // move past space

    // parse which side to move
    if(current_char == 'w')
    {
        to_move = 0;
    }
    else if(current_char == 'b')
    {
        to_move = 1;
    }
    else
    {
        fprintf(stderr, "Error: Invalid FEN format");
        return NULL;
    }
    i+=2; // move past space
    current_char = fen[i];

    // parse castling 
    castling = 0;
    if(current_char == 'K')
    {
        castling |= 1<<3;
        current_char = fen[++i];
    }
    if(current_char == 'Q')
    {
        castling |= 1<<2;
        current_char = fen[++i];
    }
    if(current_char == 'k')
    {
        castling |= 1<<1;
        current_char = fen[++i];
    }
    if(current_char == 'q')
    {
        castling |= 1;
        current_char = fen[++i];
    }
    if(current_char != 'K' && current_char != 'Q' &&
            current_char != 'k' && current_char != 'q' && current_char != ' ')
    {
        fprintf(stderr, "Error: Invalid FEN format");
        return NULL;
    }
    current_char = fen[++i]; // move past space

    // parse en passent target
    if(current_char == '-')
    {
        en_passant = -1;
    }
    else 
    {
        char file = current_char;
        current_char = fen[++i];
        char rank = current_char;
        en_passant = get_shift_value(file, rank);
    }
    i+=2; // move past space
    current_char = fen[i];

    // parse halfmoves 
    if(isdigit(current_char))
    {
        halfmove_clock = (int) current_char - 48; // subtract 48 because of ascii
    }
    else
    {
        fprintf(stderr, "Error: Invalid FEN format");
        return NULL;
    }
    i+=2; // move past space
    current_char = fen[i];

    // parse fullmoves
    if(isdigit(current_char))
    {
        fullmove_count = (int) current_char - 48; // subtract 48 because of ascii
    }
    else
    {
        fprintf(stderr, "Error: Invalid FEN format");
        return NULL;
    }

    return b;
}

int get_shift_value(char file, char rank)
{
    int file_int = (int) file - 97; // subtract 97 because of ascii
    int rank_int = (int) rank - 48; // subtract 48 because of ascii
    return (8-rank_int)*8 + file_int; // (8 - rank_int) due to bitboard structure
}

board* insert_piece(board* b, char piece, int shift_value)
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
    //todo: validate square is vacant, validate 1 king?
    bitboard start = (bitboard) 1; //cast to bitboard to prevent shift overflow
    if(piece == 'K') b->white_king = b->white_king | start << shift_value;
    if(piece == 'Q') b->white_queen = b->white_queen | start << shift_value;
    if(piece == 'B') b->white_bishops = b->white_bishops | start << shift_value;
    if(piece == 'N') b->white_knights = b->white_knights | start << shift_value;
    if(piece == 'R') b->white_rooks = b->white_rooks | start << shift_value;
    if(piece == 'P') b->white_pawns = b->white_pawns | start << shift_value;
    if(piece == 'k') b->black_king = b->black_king | start << shift_value;
    if(piece == 'q') b->black_queen = b->black_queen | start << shift_value;
    if(piece == 'b') b->black_bishops = b->black_bishops | start << shift_value;
    if(piece == 'n') b->black_knights = b->black_knights | start << shift_value;
    if(piece == 'r') b->black_rooks = b->black_rooks | start << shift_value;
    if(piece == 'p') b->black_pawns = b->black_pawns | start << shift_value;
    return b;
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

    printf("\n");
    printf("to move: %d", to_move);
    printf("\n");
    printf("castling: %d", castling);
    printf("\n");
    printf("en passant: %d", en_passant);
    printf("\n");
    printf("halfmoves: %d", halfmove_clock);
    printf("\n");
    printf("move: %d", fullmove_count);
    printf("\n");
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
    char* starting_position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    return parse_fen(starting_position);
}
