#ifndef MOVELIST_H
#define MOVELIST_H

#include <bitboard.h>
#include <board.h>

typedef struct move
{
    int is_capture;
    int is_en_passant;
    int promotion; // 0 if none, 1 if queen, 2 if rook, 3 if bishop, 4 if knight
    char piece; 
    bitboard current; // current square shift value
    bitboard target; // target square shift value
} move;

typedef struct move_node
{
    move data;
    struct move_node* next;
} move_node;

typedef struct move_list
{
    move_node* head;
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

#endif
