#include <stdio.h>
#include <movegen.h>
#include <pawns.h>
#include <knights.h>
#include <sliding_pieces.h>

// function prototypes
void generate_queen_moves(move_list* list, board* b);
void generate_bishop_moves(move_list* list, board* b);
void generate_rook_moves(move_list* list, board* b);
void generate_king_moves(move_list* list, board* b);
void generate_castling_moves(move_list* list, board* b);

move_list* generate_moves(board* b)
{
    move_list* list = init_list();
    generate_pawn_moves(list, b);
    generate_queen_moves(list, b);
    generate_bishop_moves(list, b);
    generate_knight_moves(list, b);
    generate_rook_moves(list, b);
    generate_king_moves(list, b);
    generate_castling_moves(list, b);
    return list;
}

void generate_queen_moves(move_list* list, board* b)
{
    int i;
    if(!b->to_move) // white to move
    {
        if(b->white_queen)
        {
            for(i = 0; i < 64; i++)
            {
                bitboard mask = start << i;
                if(b->white_queen & mask)
                {
                    slide_straight(list, b, 'Q', mask);
                    slide_diagonal(list, b, 'Q', mask);
                }
            }
        }
    }
    else
    {
        if(b->black_queen)
        {
            for(i = 0; i < 64; i++)
            {
                bitboard mask = start << i;
                if(b->black_queen & mask)
                {
                    slide_straight(list, b, 'q', mask);
                    slide_diagonal(list, b, 'q', mask);
                }
            }
        }
    }
}

void generate_bishop_moves(move_list* list, board* b)
{
    int i;
    if(!b->to_move) // white to move
    {
        if(b->white_bishops)
        {
            for(i = 0; i < 64; i++)
            {
                bitboard mask = start << i;
                if(b->white_bishops & mask)
                {
                    slide_diagonal(list, b, 'B', mask);
                }
            }
        }
    }
    else
    {
        if(b->black_bishops)
        {
            for(i = 0; i < 64; i++)
            {
                bitboard mask = start << i;
                if(b->black_bishops & mask)
                {
                    slide_diagonal(list, b, 'b', mask);
                }
            }
        }
    }
}

void generate_rook_moves(move_list* list, board* b)
{
    int i;
    if(!b->to_move) // white to move
    {
        if(b->white_rooks)
        {
            for(i = 0; i < 64; i++)
            {
                bitboard mask = start << i;
                if(b->white_rooks & mask)
                {
                    slide_straight(list, b, 'R', mask);
                }
            }
        }
    }
    else
    {
        if(b->black_rooks)
        {
            for(i = 0; i < 64; i++)
            {
                bitboard mask = start << i;
                if(b->black_rooks & mask)
                {
                    slide_straight(list, b, 'r', mask);
                }
            }
        }
    }
}

void generate_king_moves(move_list* list, board* b)
{
    int i;
    if(!b->to_move) // white to move
    {
        if(b->white_king)
        {
            for(i = 0; i < 64; i++)
            {
                bitboard mask = start << i;
                if(b->white_king & mask)
                {
                    slide_straight(list, b, 'K', mask);
                    slide_diagonal(list, b, 'K', mask);
                }
            }
        }
    }
    else
    {
        if(b->black_king)
        {
            for(i = 0; i < 64; i++)
            {
                bitboard mask = start << i;
                if(b->black_king & mask)
                {
                    slide_straight(list, b, 'k', mask);
                    slide_diagonal(list, b, 'k', mask);
                }
            }
        }
    }
}

void generate_castling_moves(move_list* list, board* b)
{
    bitboard start = (bitboard) 1;
    int white_kingside = 1 << 3;
    int white_queenside = 1 << 2;
    int black_kingside = 1 << 1;
    int black_queenside = 1;
    if(!b->to_move) // white to move
    {
        if(b->castling & white_kingside) // castling rights exist
        {
            if(b->white_king & start << 60 && // king is on original square
                    b->white_rooks & start << 63 && // rook is on original square
                    b->empty_squares & start << 61 && // squares in between are vacant
                    b->empty_squares & start << 62)
            {
                move m = 
                {
                    .is_capture = 0,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'K',
                    .piece = 'x',
                    .origin = 0,
                    .target = 0
                };
                add_move(list, m);
            }
        }
        if(b->castling & white_queenside)
        {
            if(b->white_king & start << 60 && // king is on original square
                    b->white_rooks & start << 56 && // rook is on original square
                    b->empty_squares & start << 57 && // squares in between are vacant
                    b->empty_squares & start << 58 &&
                    b->empty_squares & start << 59)
            {
                move m = 
                {
                    .is_capture = 0,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'Q',
                    .piece = 'x',
                    .origin = 0,
                    .target = 0
                };
                add_move(list, m);
            }
        }
    }
    else // black to move
    {
        if(b->castling & black_kingside) // castling rights exist
        {
            if(b->black_king & start << 4 && // king is on original square
                    b->black_rooks & start << 7 && // rook is on original square
                    b->empty_squares & start << 5 && // squares in between are vacant
                    b->empty_squares & start << 6)
            {
                move m = 
                {
                    .is_capture = 0,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'K',
                    .piece = 'x',
                    .origin = 0,
                    .target = 0
                };
                add_move(list, m);
            }
        }
        if(b->castling & black_queenside)
        {
            if(b->black_king & start << 4 && // king is on original square
                    b->black_rooks & start << 0 && // rook is on original square
                    b->empty_squares & start << 1 && // squares in between are vacant
                    b->empty_squares & start << 2 &&
                    b->empty_squares & start << 3)
            {
                move m = 
                {
                    .is_capture = 0,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'Q',
                    .piece = 'x',
                    .origin = 0,
                    .target = 0
                };
                add_move(list, m);
            }
        }
    }
}


