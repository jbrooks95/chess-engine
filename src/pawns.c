#include <pawns.h>

bitboard start = (bitboard) 1;

void generate_pawn_moves(move_list* list, board* b)
{
    int i;

    if(!b->to_move) // white to move
    {
        for(i = 8; i < 56; i++) // 8 to 56 because no pawns on 1st and 8th ranks
        {
            bitboard mask = start << i;
            if(b->white_pawns & mask)
            {
                //move up
                if(shift_up(mask) & b->empty_squares)
                {
                    if(!(mask & RANK_7))
                    {
                        //moves
                        move m = 
                        {
                            .is_capture = 0,
                            .is_en_passant = 0,
                            .promotion = 0,
                            .piece = 'P',
                            .origin = mask,
                            .target = shift_up(mask)
                        };
                        add_move(list, m);
                        if(mask & RANK_2 && shift_up(shift_up(mask)) & b->empty_squares) // for 2-square moves
                        {
                            m.target = shift_up(shift_up(mask));
                            add_move(list, m);
                        }
                    }
                    else
                    {
                        //handle promotion
                        move m = 
                        {
                            .is_capture = 0,
                            .is_en_passant = 0,
                            .promotion = 1,
                            .piece = 'P',
                            .origin = mask,
                            .target = shift_up(mask)
                        };
                        add_move(list, m);
                        m.promotion = 2; 
                        add_move(list, m);
                        m.promotion = 3;
                        add_move(list, m);
                        m.promotion = 4;
                        add_move(list, m);
                    }
                }
                //capture up left
                if(!(mask & FILE_A)) 
                {
                    //handle en passant
                    if(b->en_passant != -1)
                    {
                        bitboard en_passant = start << b->en_passant;
                        if(shift_up_left(mask) & en_passant)
                        {
                            move m = 
                            {
                                .is_capture = 1,
                                .is_en_passant = 1,
                                .promotion = 0,
                                .piece = 'P',
                                .origin = mask,
                                .target = shift_up_left(mask)
                            };
                            add_move(list, m);
                        }
                    }
                    if(shift_up_left(mask) & b->black_pieces)
                    {
                        if(!(mask & RANK_7))
                        {
                            //normal capture
                            move m = 
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'P',
                                .origin = mask,
                                .target = shift_up_left(mask)
                            };
                            add_move(list, m);
                        }
                        else
                        {
                            //handle promotion
                            move m = 
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 1,
                                .piece = 'P',
                                .origin = mask,
                                .target = shift_up_left(mask)
                            };
                            add_move(list, m);
                            m.promotion = 2; 
                            add_move(list, m);
                            m.promotion = 3;
                            add_move(list, m);
                            m.promotion = 4;
                            add_move(list, m);
                        }
                    }
                }
                //capture up right
                if(!(mask & FILE_H)) 
                {
                    //handle en passant
                    if(b->en_passant != -1)
                    {
                        bitboard en_passant = start << b->en_passant;
                        if(shift_up_right(mask) & en_passant)
                        {
                            move m = 
                            {
                                .is_capture = 1,
                                .is_en_passant = 1,
                                .promotion = 0,
                                .piece = 'P',
                                .origin = mask,
                                .target = shift_up_right(mask)
                            };
                            add_move(list, m);
                        }
                    }
                    if(shift_up_right(mask) & b->black_pieces)
                    {
                        if(!(mask & RANK_7))
                        {
                            //normal capture
                            move m = 
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'P',
                                .origin = mask,
                                .target = shift_up_right(mask)
                            };
                            add_move(list, m);
                        }
                        else
                        {
                            //handle promotion
                            move m = 
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 1,
                                .piece = 'P',
                                .origin = mask,
                                .target = shift_up_right(mask)
                            };
                            add_move(list, m);
                            m.promotion = 2; 
                            add_move(list, m);
                            m.promotion = 3;
                            add_move(list, m);
                            m.promotion = 4;
                            add_move(list, m);
                        }
                    }
                }
            }
        }
    }
    else // black to move
    {
        for(i = 8; i < 56; i++) // 8 to 56 because no pawns on 1st and 8th ranks
        {
            bitboard mask = start << i;
            if(b->black_pawns & mask)
            {
                //move down
                if(shift_down(mask) & b->empty_squares)
                {
                    if(!(mask & RANK_2))
                    {
                        //moves
                        move m = 
                        {
                            .is_capture = 0,
                            .is_en_passant = 0,
                            .promotion = 0,
                            .piece = 'P',
                            .origin = mask,
                            .target = shift_down(mask)
                        };
                        add_move(list, m);
                        if(mask & RANK_7 && shift_down(shift_down(mask)) & b->empty_squares) // for 2-square moves
                        {
                            m.target = shift_down(shift_down(mask));
                            add_move(list, m);
                        }
                    }
                    else
                    {
                        //handle promotion
                        move m = 
                        {
                            .is_capture = 0,
                            .is_en_passant = 0,
                            .promotion = 1,
                            .piece = 'P',
                            .origin = mask,
                            .target = shift_down(mask)
                        };
                        add_move(list, m);
                        m.promotion = 2; 
                        add_move(list, m);
                        m.promotion = 3;
                        add_move(list, m);
                        m.promotion = 4;
                        add_move(list, m);
                    }
                }
                //capture down left
                if(!(mask & FILE_A)) 
                {
                    //handle en passant
                    if(b->en_passant != -1)
                    {
                        bitboard en_passant = start << b->en_passant;
                        if(shift_down_left(mask) & en_passant)
                        {
                            move m = 
                            {
                                .is_capture = 1,
                                .is_en_passant = 1,
                                .promotion = 0,
                                .piece = 'P',
                                .origin = mask,
                                .target = shift_down_left(mask)
                            };
                            add_move(list, m);
                        }
                    }
                    if(shift_down_left(mask) & b->white_pieces)
                    {
                        if(!(mask & RANK_2))
                        {
                            //normal capture
                            move m = 
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'P',
                                .origin = mask,
                                .target = shift_down_left(mask)
                            };
                            add_move(list, m);
                        }
                        else
                        {
                            //handle promotion
                            move m = 
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 1,
                                .piece = 'P',
                                .origin = mask,
                                .target = shift_down_left(mask)
                            };
                            add_move(list, m);
                            m.promotion = 2; 
                            add_move(list, m);
                            m.promotion = 3;
                            add_move(list, m);
                            m.promotion = 4;
                            add_move(list, m);
                        }
                    }
                }
                //capture down right
                if(!(mask & FILE_H)) 
                {
                    //handle en passant
                    if(b->en_passant != -1)
                    {
                        bitboard en_passant = start << b->en_passant;
                        if(shift_down_right(mask) & en_passant)
                        {
                            move m = 
                            {
                                .is_capture = 1,
                                .is_en_passant = 1,
                                .promotion = 0,
                                .piece = 'P',
                                .origin = mask,
                                .target = shift_down_right(mask)
                            };
                            add_move(list, m);
                        }
                    }
                    if(shift_down_right(mask) & b->white_pieces)
                    {
                        if(!(mask & RANK_2))
                        {
                            //normal capture
                            move m = 
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'P',
                                .origin = mask,
                                .target = shift_down_right(mask)
                            };
                            add_move(list, m);
                        }
                        else
                        {
                            //handle promotion
                            move m = 
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 1,
                                .piece = 'P',
                                .origin = mask,
                                .target = shift_down_right(mask)
                            };
                            add_move(list, m);
                            m.promotion = 2; 
                            add_move(list, m);
                            m.promotion = 3;
                            add_move(list, m);
                            m.promotion = 4;
                            add_move(list, m);
                        }
                    }
                }
            }
        }
    }
}
