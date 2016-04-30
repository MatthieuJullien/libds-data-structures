#include "libds.h"

int     llist_indexof(t_llist *list, const void *val, int(*cmp)())
{
    t_llnode    *cur;
    int         i;

    if (list == NULL || cmp == NULL)
        return (-1);
    cur = list->first;
    i = 0;
    while (cur != NULL)
    {
        if (cmp(cur->val, val) == 1)
            return (i);
        cur = cur->next;
        i++;
    }
    return (-1);
}
