#include <movelist.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <pickmove.h>
#include <evaluate.h>
#include <movegen.h>
#include <string.h>
#include <move.h>

//function prototypes
int min(int, int);
int max(int, int);

move pick_move(board* b, int search_depth)
{
    printf("original eval: %d\n", evaluate(b));
    int is_maximizing_player;
    int best_val;
    if(!(b->to_move)) //white to move
    {
        is_maximizing_player = 1;
        best_val = INT_MIN;
    }
    else //black to move
    {
        is_maximizing_player = 0;
        best_val = INT_MAX;
    }
    printf("best val %d\n", best_val);
    move best_move;

    move_list* list = generate_moves(b);
    move_node* current = list->head;
    while(current != NULL)
    {
        board* new_position = make_move(b, current->data);
        if(new_position != NULL) //if move was legal
        {
            int result = minimax(new_position, 0, search_depth, is_maximizing_player, INT_MIN, INT_MAX);
            printf("current: ");
            print_move(current->data);
            printf(" result: %d\n", result);
            if(is_maximizing_player)
            {
                if(result > best_val)
                {
                    best_val = result;
                    best_move = current->data;
                }
            }
            else
            {
                if(result < best_val)
                {
                    best_val = result;
                    best_move = current->data;
                }
            }
        }
        current = current->next;
        free(new_position);
    }
    free_list(list);
    return best_move;
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
        int best_val = INT_MIN;

        move_list* list = generate_moves(b);
        move_node* current = list->head;
        while(current != NULL)
        {
            board* new_position = make_move(b, current->data);
            if(new_position != NULL) //if move was legal
            {
                int value = minimax(new_position, depth+1, max_depth, 0, alpha, beta);
                best_val = max(best_val, value);
                alpha = max(alpha, best_val);
                if(beta <= alpha)
                {
                    free(new_position);
                    break;
                }
            }
            current = current->next;
            free(new_position);
        }
        free_list(list);
        //todo check for checkmate here
        return best_val;
    }
    else //black to play
    {
        int best_val = INT_MAX;

        move_list* list = generate_moves(b);
        move_node* current = list->head;
        while(current != NULL)
        {
            board* new_position = make_move(b, current->data);
            if(new_position != NULL) //if move was legal
            {
                int value = minimax(new_position, depth+1, max_depth, 1, alpha, beta);
                best_val = min(best_val, value);
                beta = min(beta, best_val);
                if(beta <= alpha)
                {
                    free(new_position);
                    break;
                }
            }
            current = current->next;
            free(new_position);
        }
        free_list(list);
        return best_val;
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
