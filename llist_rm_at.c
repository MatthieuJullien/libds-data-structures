#include "libds.h"

void    llist_rm_at(t_llist *list, unsigned int index)
{
    t_llnode    *prv;
    t_llnode    *cur;

    if (index > list->size - 1)
        return ;
    if (index == 0)
    {
        cur = list->first;
        list->first = list->first->next;
        llist_destroy_node(&cur);
        return ;
    }
    cur = list->first;
    while (index > 0)
    {
        prv = cur;
        cur = cur->next;
        index--;
    }
    prv->next = cur->next;
    if (cur->next == NULL)
        list->last = prv;
    llist_destroy_node(&cur);
    list->size--;
}
