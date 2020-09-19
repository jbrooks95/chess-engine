#include <square_control.h>
#include <static_bitboards.h>
#include <shift.h>
#include <stdio.h>
#include <movegen.h>

int* get_control(int color, board* b, int* control_array);
void get_white_pawn_control(bitboard pawns, int* control_array);
void get_black_pawn_control(bitboard pawns, int* control_array);
void get_piece_control(int to_move, board* b, int* control_array);

int* get_control(int color, board* b, int control_array[])
{
    if(color == 0)
    {
        get_white_pawn_control(b->white_pawns, control_array);
    }
    else
    {
        get_black_pawn_control(b->black_pawns, control_array);
    }
    get_piece_control(color, b, control_array);
    print_control_array(control_array);
    return control_array;
}

int* get_white_control(board* b, int control_array[])
{
    return get_control(0, b, control_array);
}

int* get_black_control(board* b, int control_array[])
{
    return get_control(1, b, control_array);
}

void print_control_array(int control_array[])
{
    int i, j;
    for(i = 0; i < 64; i++)
    {
        if(i % 8 == 0) printf("\n");
        printf("[%d]", control_array[i]);
    }
    printf("\n");
}

void get_piece_control(int to_move, board* b, int control_array[])
{
    int original_to_move = b->to_move;
    int original_white_pieces = b->white_pieces;
    int original_black_pieces = b->white_pieces;

    //manipulate board to manipulate move gen outcome
    b->to_move = to_move;
    b->white_pieces = b->all_pieces;
    b->black_pieces = b->all_pieces;

    //reuse move gen to find square control
    move_list* list = generate_moves(b);
    move_node* current = list->head;
    while(current != NULL)
    {
        if(!current->data.promotion &&
                current->data.castling == 'x' &&
                current->data.piece != 'p' &&
                current->data.piece != 'P')
        {
            control_array[get_index_from_bitboard(current->data.target)]++;
        }
        current = current->next;
    }

    b->to_move = original_to_move;
    b->white_pieces = original_white_pieces;
    b->black_pieces = original_black_pieces;
}

void get_white_pawn_control(bitboard pawns, int control_array[])
{
    int i;
    for(i = 8; i < 56; i++) // 8 to 56 because no pawns on 1st and 8th ranks
    {
        bitboard mask = start << i;
        if(pawns & mask)
        {
            //check up left
            if(!(mask & FILE_A))
            {
                control_array[i - 9]++;
            }
            //check up right
            if(!(mask & FILE_H))
            {
                control_array[i - 7]++;
            }
        }
    }
}

void get_black_pawn_control(bitboard pawns, int control_array[])
{
    int i;
    for(i = 8; i < 56; i++) // 8 to 56 because no pawns on 1st and 8th ranks
    {
        bitboard mask = start << i;
        if(pawns & mask)
        {
            //check down left
            if(!(mask & FILE_A))
            {
                control_array[i + 7]++;
            }
            //check down right
            if(!(mask & FILE_H))
            {
                control_array[i + 9]++;
            }
        }
    }
}

