#include "libds.h"

void    llist_sorted_insert(t_llist *list, void *val, size_t val_size, 
        int (*cmp)())
{
    t_llnode    *new;
    t_llnode    *prv;
    t_llnode    *cur;

    if (!list || !cmp || !(new = llist_create_node(val, val_size)))
        return ;
    list->size++;
    prv = NULL;
    cur = list->first;
    while (cur)
    {
        if (cmp(val, cur->val) <= 0)
        {
            if (prv == NULL)
                list->first = new;
            else
                prv->next = new;
            new->next = cur;
            return ;
        }
        prv = cur;
        cur = cur->next;
    }
    prv->next = new;
    list->last = new;
}
