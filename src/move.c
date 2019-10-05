#include <move.h>
#include <stdlib.h>
#include <static_bitboards.h>
#include <movegen.h>
#include <movelist.h>

// These functions return the bitboards of squares
// that if logically ANDed with the correct enemy
// pieces will determine if kind is in check
bitboard get_straight_squares(bitboard king, board* b);
bitboard get_diagonal_squares(bitboard king, board* b);

board* make_move(board* b, move m)
{
    return NULL;
}

int is_king_checked(board* b)
{
    bitboard king;

    if(!b->to_move) // white to move
    {
        // check to see if black king is in check
        king = b->black_king;
    }
    else // black to move
    {
        // check to see if white king is in check
        king = b->white_king;
    }


    move_list* list = generate_moves(b);
    move_node* current = list->head;
    while(current != NULL)
    {
        move m = current->data;
        if(m.is_capture)
        {
            if(m.target & king)
            {
                return 1;
            }
        }
        current = current->next;
    }
    return 0;
}
