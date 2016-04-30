#include "libds.h"

void    llist_rm_last(t_llist *list)
{
    t_llnode    *cur;
    t_llnode    *node;

    if (list == NULL || list->size == 0)
        return ;
    node = list->last;
    if (list->size == 1)
        list->last = list->first = NULL;
    else
    {
        cur = list->first;
        while (cur->next != list->last)
            cur = cur->next;
        cur->next = NULL;
        list->last = cur;
    }
    llist_destroy_node(&node);
    list->size--;
}
