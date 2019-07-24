#include <knights.h>

void generate_knight_moves(move_list* list, board* b)
{
    int i;
    if(!b->to_move) // white to move
    {
        bitboard enemy_pieces = b->black_pieces;
        if(b->white_knights)
        {
            for(i = 0; i < 64; i++)
            {
                bitboard mask = start << i;
                if(b->white_knights & mask)
                {
                    if(!(mask & RANK_7) && !(mask & RANK_8) && !(mask & FILE_A)) //up up left
                    {
                        if(shift_up(shift_up(shift_left(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_up(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_up(shift_up(shift_left(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_up(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_7) && !(mask & RANK_8) && !(mask & FILE_H)) //up up right
                    {
                        if(shift_up(shift_up(shift_right(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_up(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_up(shift_up(shift_right(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_up(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_8) && !(mask & FILE_A) && !(mask & FILE_B)) //up left left
                    {
                        if(shift_up(shift_left(shift_left(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_left(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_up(shift_left(shift_left(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_left(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_8) && !(mask & FILE_G) && !(mask & FILE_H)) //up right right
                    {
                        if(shift_up(shift_right(shift_right(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_right(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_up(shift_right(shift_right(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_right(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_1) && !(mask & RANK_2) && !(mask & FILE_A)) //down down left
                    {
                        if(shift_down(shift_down(shift_left(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_down(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_down(shift_down(shift_left(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_down(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_1) && !(mask & RANK_2) && !(mask & FILE_H)) //down down right
                    {
                        if(shift_down(shift_down(shift_right(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_down(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_down(shift_down(shift_right(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_down(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_1) && !(mask & FILE_A) && !(mask & FILE_B)) //down left left
                    {
                        if(shift_down(shift_left(shift_left(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_left(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_down(shift_left(shift_left(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_left(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_1) && !(mask & FILE_G) && !(mask & FILE_H)) //down right right
                    {
                        if(shift_down(shift_right(shift_right(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_right(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_down(shift_right(shift_right(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_right(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                    }
                }
            }
        }
    }
    else // black to move
    {
        bitboard enemy_pieces = b->white_pieces;
        if(b->black_knights)
        {
            for(i = 0; i < 64; i++)
            {
                bitboard mask = start << i;
                if(b->black_knights & mask)
                {
                    if(!(mask & RANK_7) && !(mask & RANK_8) && !(mask & FILE_A)) //up up left
                    {
                        if(shift_up(shift_up(shift_left(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_up(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_up(shift_up(shift_left(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_up(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_7) && !(mask & RANK_8) && !(mask & FILE_H)) //up up right
                    {
                        if(shift_up(shift_up(shift_right(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_up(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_up(shift_up(shift_right(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_up(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_8) && !(mask & FILE_A) && !(mask & FILE_B)) //up left left
                    {
                        if(shift_up(shift_left(shift_left(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_left(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_up(shift_left(shift_left(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_left(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_8) && !(mask & FILE_G) && !(mask & FILE_H)) //up right right
                    {
                        if(shift_up(shift_right(shift_right(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_right(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_up(shift_right(shift_right(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_up(shift_right(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_1) && !(mask & RANK_2) && !(mask & FILE_A)) //down down left
                    {
                        if(shift_down(shift_down(shift_left(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_down(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_down(shift_down(shift_left(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_down(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_1) && !(mask & RANK_2) && !(mask & FILE_H)) //down down right
                    {
                        if(shift_down(shift_down(shift_right(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_down(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_down(shift_down(shift_right(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_down(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_1) && !(mask & FILE_A) && !(mask & FILE_B)) //down left left
                    {
                        if(shift_down(shift_left(shift_left(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_left(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_down(shift_left(shift_left(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_left(shift_left(mask)))
                            };
                            add_move(list, m);
                        }
                    }

                    if(!(mask & RANK_1) && !(mask & FILE_G) && !(mask & FILE_H)) //down right right
                    {
                        if(shift_down(shift_right(shift_right(mask))) & b->empty_squares)
                        {
                            move m =
                            {
                                .is_capture = 0,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_right(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                        else if(shift_down(shift_right(shift_right(mask))) & enemy_pieces)
                        {
                            move m =
                            {
                                .is_capture = 1,
                                .is_en_passant = 0,
                                .promotion = 0,
                                .piece = 'N',
                                .origin = mask,
                                .target = shift_down(shift_right(shift_right(mask)))
                            };
                            add_move(list, m);
                        }
                    }
                }
            }
        }
    }
}
