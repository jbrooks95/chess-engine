#include <stdio.h>
#include <movegen.h>
#include <static_bitboards.h>

// function prototypes
move_list* generate_pawn_moves(move_list*, board* b);
move_list* generate_king_moves(move_list*, board* b);
move_list* generate_queen_moves(move_list*, board* b);
move_list* generate_bishop_moves(move_list*, board* b);
move_list* generate_knight_moves(move_list*, board* b);
move_list* generate_rook_moves(move_list*, board* b);
bitboard shift_left(bitboard b);
bitboard shift_right(bitboard b);
bitboard shift_up(bitboard b);
bitboard shift_up_left(bitboard b);
bitboard shift_up_right(bitboard b);
bitboard shift_down(bitboard b);
bitboard shift_down_left(bitboard b);
bitboard shift_down_right(bitboard b);

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

bitboard start = (bitboard) 1;

move_list* generate_moves(board* b)
{
    move_list* list = init_list();
    //generate_king_moves();
    //generate_queen_moves();
    //generate_bishop_moves();
    //generate_knight_moves();
    //generate_rook_moves();
    generate_pawn_moves(list, b);
    return list;
}

move_list* generate_pawn_moves(move_list* list, board* b)
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
    return list;
}


int is_king_checked(board* b)
{
}

bitboard shift_up(bitboard b) { return b >> 8; }
bitboard shift_down(bitboard b) { return b << 8; }
bitboard shift_left(bitboard b) { return b >> 1; }
bitboard shift_right(bitboard b) { return b << 1; }
bitboard shift_up_left(bitboard b) { return b >> 9; }
bitboard shift_up_right(bitboard b) { return b >> 7; }
bitboard shift_down_left(bitboard b) { return b << 7; }
bitboard shift_down_right(bitboard b) { return b << 9; }

