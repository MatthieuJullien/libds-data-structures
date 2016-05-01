#include "libds.h"
#include <stdlib.h>

t_llist   *llist_to_set(t_llist *list, int (*cmp)())
{
    t_llist     *set;
    t_llnode    *cur;

    llist_create(&set);
    if (set == NULL)
        return (NULL);
    cur = list->first;
    while (cur)
    {
        llist_add_nodup(set, cur->val, cur->val_size, cmp);
        cur = cur->next;
    }
    return (set);
}
