#include <move.h>
#include <stdlib.h>
#include <static_bitboards.h>
#include <movegen.h>
#include <movelist.h>

bitboard get_shift_value_from_value(bitboard value);

board* make_move(board* b, move m)
{
    bitboard start = (bitboard) 1;
    int halfmove_set = 0;
    // remove captured pieces
    if(m.is_capture)
    {
        if(!b->to_move) // white to move
        {
            if(m.is_en_passant)
            {
                b->black_pawns = b->black_pawns ^ shift_down(m.target);
            }
            else
            {
                b->black_pawns ^= m.target;
                b->black_knights ^= m.target;
                b->black_bishops ^= m.target;
                b->black_rooks ^= m.target;
                b->black_queen ^= m.target;
                //b->black_king ^= m.target; //should not occur
            }
        }
        else // black to move
        {
         if(m.is_en_passant)
            {
                b->white_pawns = b->white_pawns ^ shift_up(m.target);
            }
            else
            {
                b->white_pawns ^= m.target;
                b->white_knights ^= m.target;
                b->white_bishops ^= m.target;
                b->white_rooks ^= m.target;
                b->white_queen ^= m.target;
                //b->white_king ^= m.target; //should not occur
            }
        }
    }
    // insert piece on target square and remove from origin
    switch(m.piece)
    {
        case 'P':
            b->white_pawns ^= m.origin; //remove
            b->white_pawns |= m.target; //insert
            if(shift_up(shift_up(m.origin) == m.target))
            {
                b->en_passant = get_shift_value_from_value(shift_up(m.origin));
            }
            b->halfmove_clock++;
            break;
        case 'p':
            b->black_pawns ^= m.origin; //remove
            b->black_pawns |= m.target; //insert
            if(shift_down(shift_down(m.origin) == m.target))
            {
                b->en_passant = get_shift_value_from_value(shift_down(m.origin));
            }
            b->halfmove_clock++;
            break;
        case 'N':
            b->white_knights ^= m.origin;
            b->white_knights |= m.target;
            break;
        case 'B':
            b->white_bishops ^= m.origin;
            b->white_bishops |= m.target;
            break;
        case 'b':
            b->black_bishops ^= m.origin;
            b->black_bishops |= m.target;
            break;
        case 'n':
            b->black_knights ^= m.origin;
            b->black_knights |= m.target;
            break;
        case 'R':
            b->white_rooks ^= m.origin;
            b->white_rooks |= m.target;
            if(m.origin == start<<56)
            {
                b->castling &= ~(1<<2); // remove castling rights
            }
            else if(m.origin == start<<63)
            {
                b->castling &= ~(1<<3); // remove castling rights
            }
            break;
        case 'r':
            b->black_rooks ^= m.origin;
            b->black_rooks |= m.target;
            if(m.origin == start<<0)
            {
                b->castling &= ~1; // remove castling rights
            }
            else if(m.origin == start<<7)
            {
                b->castling &= ~(1<<1); // remove castling rights
            }
            break;
        case 'Q':
            b->white_queen ^= m.origin;
            b->white_queen |= m.target;
            break;
        case 'q':
            b->black_queen ^= m.origin;
            b->black_queen |= m.target;
            break;
        case 'K':
            b->white_king ^= m.origin;
            b->white_king |= m.target;
            b->castling &= ~(3<<2); // remove castling rights
            break;
        case 'k':
            b->black_king ^= m.origin;
            b->black_king |= m.target;
            b->castling &= ~3; // remove castling rights
            break;

    }
    set_all_pieces(b);
    //todo: halfmove clock
    if(!halfmove_set)
    {
        if(is_king_checked(b))
        {
            b->halfmove_clock++;
        }
    }
    if(b->to_move)
    {
        b->fullmove_count++;
        b->to_move = 0;
    }
    else
    {
        b->to_move = 1;
    }
    return b;
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

bitboard get_shift_value_from_value(bitboard value)
{
    int shift_value = 0;
    while(!(value & 1))
    {
        value >>= 1;
        shift_value++;
    }
    return shift_value;
}
