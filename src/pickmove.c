#include <movelist.h>
#include <limits.h>
#include <stdlib.h>
#include <pickmove.h>
#include <evaluate.h>
#include <movegen.h>

int min(int, int);
int max(int, int);

move pick_move(board* b, int search_depth)
{
    int is_maximizing_player;
    int best_val;
    if(!(b->to_move)) //white to move
    {
        is_maximizing_player = 1;
        best_val = INT_MAX;
    }
    else //black to move
    {
        is_maximizing_player = 0;
        best_val = INT_MIN;
    }
    move best_move;

    move_list* list = generate_moves(b);
    move_node* current = list->head;
    while(current != NULL)
    {
        board* new_position = make_move(b, current->data);
        if(new_position != NULL) //if move was legal
        {
            int result = minimax(b, 0, search_depth, is_maximizing_player, INT_MIN, INT_MAX);
            if(is_maximizing_player)
            {
                if(result > best_val)
                {
                    best_move = current->data;
                }
            }
            else
            {
                if(result < best_val)
                {
                    best_move = current->data;
                }
            }
        }
        current = current->next;
    }
    return best_move;
}

board* make_move(board* b, move m)
{
    return NULL;
}

int minimax(board* b, int depth, int max_depth, int is_maximizing_player, int alpha, int beta)
{
    //if position is leaf node
    if(depth == max_depth)
    {
        return evaluate(b);
    }

    if(is_maximizing_player) //white to play
    {
        int best_val = INT_MAX;

        move_list* list = generate_moves(b);
        move_node* current = list->head;
        while(current != NULL)
        {
            board* new_position = make_move(b, current->data);
            if(new_position != NULL) //if move was legal
            {
                int value = minimax(new_position, depth+1, max_depth, is_maximizing_player, alpha, beta);
                best_val = min(best_val, value);
                beta = min(beta, best_val);
                if(beta <= alpha) break;
            }
            current = current->next;
        }
    }
    else //black to play
    {
        int best_val = INT_MIN;
    }

}

int min(int a, int b)
{
    if(a <= b) return a;
    else return b;
}

int max(int a, int b)
{
    if(a >= b) return a;
    else return b;
}
