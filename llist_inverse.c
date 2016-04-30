#include "libds.h"

void    llist_inverse(t_llist *list)
{
    t_llnode    *prv;
    t_llnode    *cur;
    t_llnode    *nxt;

    if (list == NULL)
        return ;
    prv = list->first;
    cur = prv->next;
    list->first = list->last;
    list->last = prv;
    prv->next = NULL;
    while (cur)
    {
        nxt = cur->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
    }
}
