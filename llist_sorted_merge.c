#include "libds.h"

void    llist_sorted_merge(t_llist *list1, t_llist *list2, int (*cmp)())
{
    t_llnode    *cur;

    cur = list2->first;
    while (cur)
    {
        llist_sorted_insert(list1, cur->val, cur->val_size, cmp);
        cur = cur->next;
    }
}
