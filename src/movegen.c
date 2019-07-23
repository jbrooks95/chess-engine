#include <stdio.h>
#include <movegen.h>
#include <pawns.h>
#include <sliding_pieces.h>

// function prototypes
void generate_queen_moves(move_list* list, board* b);

move_list* generate_moves(board* b)
{
    move_list* list = init_list();
    generate_pawn_moves(list, b);
    generate_queen_moves(list, b);
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

