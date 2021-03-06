#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <board.h>
#include <ctype.h>

board* parse_fen(char* fen)
{
    board* b = calloc(1, sizeof(board));
    int start = (bitboard) 1;

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
                fprintf(stderr, "Error: Invalid FEN format. Can't parse piece positions.");
                return NULL;
            }
        }
        current_char = fen[++i];
    }
    current_char = fen[++i]; // move past space


    // parse which side to move
    if(current_char == 'w')
    {
        b->to_move = 0;
    }
    else if(current_char == 'b')
    {
        b->to_move = 1;
    }
    else
    {
        fprintf(stderr, "Error: Invalid FEN format. Can't parse player to move.");
        return NULL;
    }
    i+=2; // move past space
    current_char = fen[i];

    // parse castling 
    b->castling = 0;
    if(current_char == 'K')
    {
        b->castling |= 1<<3;
        current_char = fen[++i];
    }
    if(current_char == 'Q')
    {
        b->castling |= 1<<2;
        current_char = fen[++i];
    }
    if(current_char == 'k')
    {
        b->castling |= 1<<1;
        current_char = fen[++i];
    }
    if(current_char == 'q')
    {
        b->castling |= 1;
        current_char = fen[++i];
    }
    if(current_char == '-')
    {
        current_char = fen[++i]; // move past dash
    }
    if(current_char != 'K' && current_char != 'Q' &&
            current_char != 'k' && current_char != 'q' && current_char != ' ')
    {
        fprintf(stderr, "Error: Invalid FEN format. Can't parse castling.");
        return NULL;
    }
    current_char = fen[++i]; // move past space

    // parse en passent target
    if(current_char == '-')
    {
        b->en_passant = -1;
    }
    else 
    {
        char file = current_char;
        current_char = fen[++i];
        char rank = current_char;
        b->en_passant = start << get_shift_value(file, rank);
    }
    current_char = fen[++i]; // move past dash
    if(current_char != '\0') // check if end of string
    {
        current_char = fen[++i]; // move past space

        // parse halfmoves 
        if(isdigit(current_char))
        {
            char value[10] = { 0 };
            while(isdigit(current_char))
            {
                strcat(value, &current_char);
                current_char = fen[++i];
            }
            b->halfmove_clock = atoi(value);
        }
        else
        {
            fprintf(stderr, "Error: Invalid FEN format. Can't parse half moves.");
            return NULL;
        }
        current_char = fen[++i]; // move past space

        // parse fullmoves
        if(isdigit(current_char))
        {
            char value[10] = { 0 };
            while(isdigit(current_char))
            {
                strcat(value, &current_char);
                current_char = fen[++i];
            }
            b->fullmove_count = atoi(value);
        }
        else
        {
            fprintf(stderr, "Error: Invalid FEN format. Can't parse full moves.");
            return NULL;
        }
    }
    else
    {
        b->halfmove_clock = 0;
        b->fullmove_count = 1;
    }

    set_all_pieces(b);
    return b;
}

void set_all_pieces(board* b)
{
    b->white_pieces = 
        b->white_king |
        b->white_queen |
        b->white_bishops |
        b->white_knights |
        b->white_rooks |
        b->white_pawns;
    b->black_pieces = 
        b->black_king |
        b->black_queen |
        b->black_bishops |
        b->black_knights |
        b->black_rooks |
        b->black_pawns;
    b->all_pieces = b->white_pieces | b->black_pieces;
    b->empty_squares = ~(b->all_pieces);
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
    
    switch(piece)
    {
        case 'K':
            b->white_king |= start << shift_value;
            break;
        case 'Q':
            b->white_queen |= start << shift_value;
            break;
        case 'B':
            b->white_bishops |= start << shift_value;
            break;
        case 'N':
            b->white_knights |= start << shift_value;
            break;
        case 'R':
            b->white_rooks |= start << shift_value;
            break;
        case 'P':
            b->white_pawns |= start << shift_value;
            break;
        case 'k':
            b->black_king |= start << shift_value;
            break;
        case 'q':
            b->black_queen |= start << shift_value;
            break;
        case 'b':
            b->black_bishops |= start << shift_value;
            break;
        case 'n':
            b->black_knights |= start << shift_value;
            break;
        case 'r':
            b->black_rooks |= start << shift_value;
            break;
        case 'p':
            b->black_pawns |= start << shift_value;
            break;
    }
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
    printf("to move: %d", b->to_move);
    printf("\n");
    printf("castling: %d", b->castling);
    printf("\n");
    printf("en passant: %d", b->en_passant);
    printf("\n");
    printf("halfmoves: %d", b->halfmove_clock);
    printf("\n");
    printf("move: %d", b->fullmove_count);
    printf("\n");
}

char get_piece(board* b, int i, int j)
{
    bitboard current_square = get_bitboard(i, j);
    if(b->white_king & current_square) return 'K';
    else if(b->white_queen & current_square) return 'Q';
    else if(b->white_bishops & current_square) return 'B';
    else if(b->white_knights & current_square) return 'N';
    else if(b->white_rooks & current_square) return 'R';
    else if(b->white_pawns & current_square) return 'P';
    else if(b->black_king & current_square) return 'k';
    else if(b->black_queen & current_square) return 'q';
    else if(b->black_bishops & current_square) return 'b';
    else if(b->black_knights & current_square) return 'n';
    else if(b->black_rooks & current_square) return 'r';
    else if(b->black_pawns & current_square) return 'p';
    return ' '; //square is vacant
}

bitboard get_bitboard(int i, int j)
{
   return ((bitboard)1) << ((i*8) + j);
}

char* get_algebraic(bitboard b)
{
    if(b && !(b & (b-1))) // Ensures only 1 bit is set
    {
        bitboard start = (bitboard) 1;
        int shift_value = -1;
        int i = 0;
        while(shift_value == -1 && i < 64)
        {
            if(start << i & b)
            {
                shift_value = i;
                break;
            }
            i++;
        }
        if(i == 64) return "Error parsing square"; // Is this check necessary?
        int mod_val = shift_value % 8;
        char file = mod_val + 97;
        char rank = (char) (8 - ((shift_value - mod_val) + 1) / 8) + 48;
        char* str = malloc(sizeof(char) * 3);
        str[0] = file;
        str[1] = rank;
        str[2] = '\0';
        return str; 
    }
    else
    {
        return "Not a valid square";
    }
}

board* init_board(void)
{
    char* starting_position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    return parse_fen(starting_position);
}
