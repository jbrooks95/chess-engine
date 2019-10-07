#include <sliding_pieces.h>
#include <stdio.h>

// function prototypes
bitboard get_enemy_pieces(board* b);
void slide_up(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin);
void slide_up_right(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin);
void slide_right(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin);
void slide_down_right(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin);
void slide_down(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin);
void slide_down_left(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin);
void slide_left(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin);
void slide_up_left(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin);

void slide_straight(move_list* list, board* b, char piece, bitboard origin)
{

    bitboard enemy_pieces = get_enemy_pieces(b);
    slide_up(list, b, enemy_pieces, piece, origin);
    slide_right(list, b, enemy_pieces, piece, origin);
    slide_down(list, b, enemy_pieces, piece, origin);
    slide_left(list, b, enemy_pieces, piece, origin);
}

void slide_diagonal(move_list* list, board* b, char piece, bitboard origin)
{
    bitboard enemy_pieces = get_enemy_pieces(b);
    slide_up_right(list, b, enemy_pieces, piece, origin);
    slide_up_left(list, b, enemy_pieces, piece, origin);
    slide_down_right(list, b, enemy_pieces, piece, origin);
    slide_down_left(list, b, enemy_pieces, piece, origin);
}

void slide_up(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin)
{
    bitboard current = origin;

    while(1)
    {
        if(!(current & RANK_8))
        {
            if(shift_up(current) & b->empty_squares)
            {
                move m =
                {
                    .is_capture = 0,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_up(current)
                };
                add_move(list, m);
                current = shift_up(current); 
            }
            else if(shift_up(current) & enemy_pieces)
            {
                move m =
                {
                    .is_capture = 1,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_up(current)
                };
                add_move(list, m);
                break;
            }
            else
            {
                break;
            }
            if(piece == 'K' || piece == 'k') break;
        }
        else
        {
            break;
        }
    }
}

void slide_down(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin)
{
    bitboard current = origin;

    while(1)
    {
        if(!(current & RANK_1))
        {
            if(shift_down(current) & b->empty_squares)
            {
                move m =
                {
                    .is_capture = 0,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_down(current)
                };
                add_move(list, m);
                current = shift_down(current); 
            }
            else if(shift_down(current) & enemy_pieces)
            {
                move m =
                {
                    .is_capture = 1,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_down(current)
                };
                add_move(list, m);
                break;
            }
            else
            {
                break;
            }
            if(piece == 'K' || piece == 'k') break;
        }
        else
        {
            break;
        }
    }
}

void slide_right(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin)
{
    bitboard current = origin;

    while(1)
    {
        if(!(current & FILE_H))
        {
            if(shift_right(current) & b->empty_squares)
            {
                move m =
                {
                    .is_capture = 0,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_right(current)
                };
                add_move(list, m);
                current = shift_right(current); 
            }
            else if(shift_right(current) & enemy_pieces)
            {
                move m =
                {
                    .is_capture = 1,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_right(current)
                };
                add_move(list, m);
                break;
            }
            else
            {
                break;
            }
            if(piece == 'K' || piece == 'k') break;
        }
        else
        {
            break;
        }
    }
}

void slide_left(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin)
{
    bitboard current = origin;

    while(1)
    {
        if(!(current & FILE_A))
        {
            if(shift_left(current) & b->empty_squares)
            {
                move m =
                {
                    .is_capture = 0,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_left(current)
                };
                add_move(list, m);
                current = shift_left(current); 
            }
            else if(shift_left(current) & enemy_pieces)
            {
                move m =
                {
                    .is_capture = 1,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_left(current)
                };
                add_move(list, m);
                break;
            }
            else
            {
                break;
            }
            if(piece == 'K' || piece == 'k') break;
        }
        else
        {
            break;
        }
    }
}

void slide_up_right(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin)
{
    bitboard current = origin;

    while(1)
    {
        if(!(current & RANK_8) && !(current & FILE_H))
        {
            if(shift_up_right(current) & b->empty_squares)
            {
                move m =
                {
                    .is_capture = 0,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_up_right(current)
                };
                add_move(list, m);
                current = shift_up_right(current); 
            }
            else if(shift_up_right(current) & enemy_pieces)
            {
                move m =
                {
                    .is_capture = 1,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_up_right(current)
                };
                add_move(list, m);
                break;
            }
            else
            {
                break;
            }
            if(piece == 'K' || piece == 'k') break;
        }
        else
        {
            break;
        }
    }
}

void slide_down_right(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin)
{
    bitboard current = origin;

    while(1)
    {
        if(!(current & RANK_1) && !(current & FILE_H))
        {
            if(shift_down_right(current) & b->empty_squares)
            {
                move m =
                {
                    .is_capture = 0,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_down_right(current)
                };
                add_move(list, m);
                current = shift_down_right(current); 
            }
            else if(shift_down_right(current) & enemy_pieces)
            {
                move m =
                {
                    .is_capture = 1,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_down_right(current)
                };
                add_move(list, m);
                break;
            }
            else
            {
                break;
            }
            if(piece == 'K' || piece == 'k') break;
        }
        else
        {
            break;
        }
    }
}

void slide_down_left(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin)
{
    bitboard current = origin;

    while(1)
    {
        if(!(current & RANK_1) && !(current & FILE_A))
        {
            if(shift_down_left(current) & b->empty_squares)
            {
                move m =
                {
                    .is_capture = 0,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_down_left(current)
                };
                add_move(list, m);
                current = shift_down_left(current); 
            }
            else if(shift_down_left(current) & enemy_pieces)
            {
                move m =
                {
                    .is_capture = 1,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_down_left(current)
                };
                add_move(list, m);
                break;
            }
            else
            {
                break;
            }
            if(piece == 'K' || piece == 'k') break;
        }
        else
        {
            break;
        }
    }
}

void slide_up_left(move_list* list, board* b, bitboard enemy_pieces, char piece, bitboard origin)
{
    bitboard current = origin;

    while(1)
    {
        if(!(current & RANK_8) && !(current & FILE_A))
        {
            if(shift_up_left(current) & b->empty_squares)
            {
                move m =
                {
                    .is_capture = 0,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_up_left(current)
                };
                add_move(list, m);
                current = shift_up_left(current); 
            }
            else if(shift_up_left(current) & enemy_pieces)
            {
                move m =
                {
                    .is_capture = 1,
                    .is_en_passant = 0,
                    .promotion = 0,
                    .castling = 'x',
                    .piece = piece,
                    .origin = origin,
                    .target = shift_up_left(current)
                };
                add_move(list, m);
                break;
            }
            else
            {
                break;
            }
            if(piece == 'K' || piece == 'k') break;
        }
        else
        {
            break;
        }
    }
}

bitboard get_enemy_pieces(board* b)
{
    bitboard enemy_pieces = (bitboard) 0; 
    if(!b->to_move) // 0 is white
    {
        enemy_pieces = b->black_pieces;
    }
    else // 1 is black
    {
        enemy_pieces = b->white_pieces;
    }
}
