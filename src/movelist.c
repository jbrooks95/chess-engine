#include <movelist.h>
#include <stdlib.h>
#include <stdio.h>

move_list* init_list()
{
    move_list* list = malloc(sizeof(move_list));
    list->head = NULL; 
    return list;
}

void add_move(move_list* list, move m)
{
    move_node* new_node = malloc(sizeof(move_node));
    new_node->data = m;
    new_node->next = list->head;
    list->head = new_node;
}

int isEmpty(move_list* list)
{
    if(list->head) return 0;
    return 1;
}

void free_list(move_list* list)
{
    move_node* temp;
    while(list->head != NULL)
    {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    free(list);
}

void print_moves(move_list* list)
{
    move_node* current = list->head;
    while(current != NULL)
    {
        print_move(current->data);
        printf("\n");
        current = current->next;
    }
}

void print_move(move m)
{
    //todo Nbxd4 Nexd4
    if(m.piece != 'P' && m.piece != 'p')
    {
        printf("%c", m.piece); //todo add to_upper()
    }
    if(m.is_capture)
    {
        printf("x");
    }
    printf(get_algebraic(m.target));
    if(m.is_en_passant)
    {
        printf("e.p.");
    }
    else if(m.promotion)
    {
        if(m.promotion == 1) printf("=Q");
        else if(m.promotion == 2) printf("=R");
        else if(m.promotion == 3) printf("=B");
        else if(m.promotion == 4) printf("=N");
    }
}
