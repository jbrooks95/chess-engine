#include <stdio.h>
#include <movegen.h>
#include <pawns.h>

move_list* generate_moves(board* b)
{
    move_list* list = init_list();
    generate_pawn_moves(list, b);
    return list;
}

int is_king_checked(board* b)
{
}
