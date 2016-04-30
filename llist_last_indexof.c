#include "libds.h"

int     llist_last_indexof(t_llist *list, const void *val, int(*cmp)())
{
    t_llnode    *cur;
    int         i;
    int         index;

    if (list == NULL || cmp == NULL)
        return (-1);
    cur = list->first;
    i = 0;
    index = -1;
    while (cur)
    {
        if (cmp(cur->val, val) == 1)
            index = i;
        cur = cur->next;
        i++;
    }
    return (index);
}
