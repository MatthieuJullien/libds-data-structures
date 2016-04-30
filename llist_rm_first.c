#include "libds.h"

void    llist_rm_first(t_llist *list)
{
    t_llnode    *node;

    if (list == NULL || list->size == 0)
        return ;
    node = list->first;
    list->first = list->first->next;
    list->size--;
    if (list->size <= 1)
        list->last = list->first;
    llist_destroy_node(&node);
}
