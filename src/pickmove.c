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
    int rand_max = 3;
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

    move best_move = 
    {
        .is_capture = 0,
        .is_en_passant = 0,
        .promotion = 0,
        .castling = 'x',
        .piece = '#',
        .origin = 0,
        .target = 0
    };

    move_list* list = generate_moves(b);
    move_node* current = list->head;
    while(current != NULL)
    {
        //value used to add some randomization move selection
        //will create a value between [1, rand_max]
        int random = rand() % rand_max + 1; 

        board* new_position = make_move(b, current->data);
        if(new_position != NULL) //if move was legal
        {
            int result = minimax(new_position, 0, search_depth, !is_maximizing_player, INT_MIN, INT_MAX);
            printf("move: ");
            print_move(current->data);
            printf(" result: %d\n", result);
            if(is_maximizing_player)
            {
                if(result > best_val)
                {
                    best_val = result;
                    best_move = current->data;
                }
                else if(result == best_val && random == rand_max && current->data.piece != '#')
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
                else if(result == best_val && random == rand_max)
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

        if(best_val == INT_MIN) //no legal moves found
        {
            if(!is_white_king_checked(b))
            {
                //stalemate
                int value = 0;
                best_val = max(best_val, value);
                
            }
            //else checkmate
        }

        free_list(list);
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

        if(best_val == INT_MAX) //no legal moves found
        {
            if(!is_black_king_checked(b))
            {
                //stalemate
                int value = 0;
                best_val = min(best_val, value);
                
            }
            //else checkmate
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
