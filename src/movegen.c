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

move_list* generate_moves(board* b)
{
    move_list* list = init_list();
    generate_pawn_moves(list, b);
    generate_queen_moves(list, b);
    generate_bishop_moves(list, b);
    generate_knight_moves(list, b);
    generate_rook_moves(list, b);
    generate_king_moves(list, b);
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


