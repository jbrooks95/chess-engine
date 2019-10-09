#ifndef MOVELIST_H
#define MOVELIST_H

#include <bitboard.h>
#include <board.h>

// 'K' White kingside castle
// 'Q' White queenside castle
// 'k' Black kingside castle
// 'q' Black queenside castle
typedef struct move
{
    int is_capture;
    int is_en_passant;
    int promotion; // 0 if none, 1 if queen, 2 if rook, 3 if bishop, 4 if knight
    char castling; // 'K', 'Q', 'k', or 'q' which maps to the KQkq in FEN
    char piece; 
    bitboard origin; // origin square value
    bitboard target; // target square value
} move;

typedef struct move_node
{
    move data;
    struct move_node* next;
} move_node;

typedef struct move_list
{
    move_node* head;
    move_node* tail;
} move_list;

/*
 * Returns a new list 
 * with head node pointer 
 * initialized to null
 */
move_list* init_list(); 

/*
 * Adds given move to the
 * front of given move
 * list
 */
void add_move(move_list* list, move m); 

/*
 * Returns 0 if not empty, 1 if
 * empty
 */
int isEmpty(move_list* list);

/*
 * Frees memory allocated to
 * the list and its nodes
 */
void free_list(move_list* list);

/*
 * Prints the list of moves
 * in algebraic notation
 */
void print_moves(move_list* list);

/*
 * Prints the origin and target squares
 * of move in algebraic notation
 */
void print_move_squares(move m);

/*
 * Prints the algebraic represenation
 * of a move
 */
void print_move(move m);

#endif
