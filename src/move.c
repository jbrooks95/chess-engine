#include <move.h>
#include <static_bitboards.h>

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
    bitboard friendly_pieces;
    bitboard enemy_queen;
    bitboard enemy_rooks;
    bitboard enemy_bishops;
    bitboard enemy_knights;
    bitboard enemy_pawns;

    if(!b->to_move) // white to move
    {
        // check to see if black king is in check
        king = b->black_king;
        friendly_pieces = b->black_pieces;
        enemy_queen = b->white_queen;
        enemy_rooks = b->white_rooks;
        enemy_bishops = b->white_bishops;
        enemy_knights = b->white_knights;
        enemy_pawns = b->white_pawns;

        // This is inside the if statement
        // because pawn checks are 
        // dependent on the color of the king
        // check for pawn checks
        if(shift_down_left(king) & b->black_pawns | shift_down_right(king) & b->black_pawns) return 1;
    }
    else // black to move
    {
        // check to see if white king is in check
        king = b->white_king;
        friendly_pieces = b->white_pieces;
        enemy_queen = b->black_queen;
        enemy_rooks = b->black_rooks;
        enemy_bishops = b->black_bishops;
        enemy_knights = b->black_knights;
        
        // check for pawn checks
        if(shift_up_left(king) & b->black_pawns | shift_up_right(king) & b->black_pawns) return 1;
    }
    
    // check for knight checks
    if(shift_up_up_left(king) & enemy_knights ||
            shift_up_up_right(king) & enemy_knights ||
            shift_up_left_left(king) & enemy_knights ||
            shift_up_right_right(king) & enemy_knights ||
            shift_down_down_right(king) & enemy_knights ||
            shift_down_down_left(king) & enemy_knights ||
            shift_down_left_left(king) & enemy_knights ||
            shift_down_right_right(king) & enemy_knights) return 1;

    // check for straight checks (rook and queen)
    bitboard straight_squares = get_straight_squares(king, b);
    if(straight_squares & enemy_queen || straight_squares & enemy_rooks) return 1;

    // check for diagonal checks (bishop and queen)
    bitboard diagonal_squares = get_diagonal_squares(king, b);
    if(diagonal_squares & enemy_queen || diagonal_squares & enemy_bishops) return 1;
}

bitboard get_straight_squares(bitboard king, board* b)
{
    bitboard ret_val = king;
    bitboard current = king;

    //go up
    while(1)
    {
        if(!(current & RANK_8))
        {
            current = shift_up(current);
            ret_val = ret_val | current;
            if(!(shift_up(current) & b->empty_squares)) break;
        }
        else break;
    }
    current = king;
    //go down
    while(1)
    {
        if(!(current & RANK_1))
        {
            current = shift_down(current);
            ret_val = ret_val | current;
            if(!(shift_down(current) & b->empty_squares)) break;
        }
        else break;
    }
    current = king;
    //go left
    while(1)
    {
        if(!(current & FILE_A))
        {
            current = shift_left(current);
            ret_val = ret_val | current;
            if(!(shift_left(current) & b->empty_squares)) break;
        }
        else break;
    }
    current = king;
    //go right
    while(1)
    {
        if(!(current & FILE_H))
        {
            current = shift_right(current);
            ret_val = ret_val | current;
            if(!(shift_right(current) & b->empty_squares)) break;
        }
        else break;
    }

    return ret_val;
}

bitboard get_diagonal_squares(bitboard king, board* b)
{
    bitboard ret_val = king;
    bitboard current = king;

    //go up left
    while(1)
    {
        if(!(current & RANK_8) && !(current & FILE_A))
        {
            current = shift_up_left(current);
            ret_val = ret_val | current;
            if(!(shift_up_left(current) & b->empty_squares)) break;
        }
        else break;
    }
    current = king;
    //go up right
    while(1)
    {
        if(!(current & RANK_8) && !(current & FILE_H))
        {
            current = shift_up_right(current);
            ret_val = ret_val | current;
            if(!(shift_up_right(current) & b->empty_squares)) break;
        }
        else break;
    }
    current = king;
    //go down left
    while(1)
    {
        if(!(current & RANK_1) && !(current & FILE_A))
        {
            current = shift_down_left(current);
            ret_val = ret_val | current;
            if(!(shift_down_left(current) & b->empty_squares)) break;
        }
        else break;
    }
    current = king;
    //go down right
    while(1)
    {
        if(!(current & RANK_1) && !(current & FILE_H))
        {
            current = shift_down_right(current);
            ret_val = ret_val | current;
            if(!(shift_down_right(current) & b->empty_squares)) break;
        }
        else break;
    }
    return ret_val;
}
