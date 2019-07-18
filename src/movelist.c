#include <movelist.h>
#include <stdlib.h>

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

