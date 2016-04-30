#include "libds.h"

void    llist_rm_at(t_llist *list, unsigned int index)
{
    t_llnode    *prv;
    t_llnode    *cur;

    if (index > list->size)
        return ;
    cur = list->first;
    while (index > 0)
    {
        prv = cur;
        cur = cur->next;
        index--;
    }
    prv->next = cur->next;
    //llist_destroy_node(&cur);
    list->size--;
}
