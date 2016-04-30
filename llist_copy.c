#include "libds.h"
#include <stdlib.h>

t_llist     *llist_copy(t_llist *list)
{
    t_llist     *copy;
    t_llnode    *cur;

    if (list == NULL)
        return (NULL);
    copy = (t_llist *)malloc(sizeof(t_llist));
    if (copy == NULL)
        return (NULL);
    cur = list->first;
    while (cur != NULL)
    {
        llist_add_last(copy, cur->val, cur->val_size);
        cur = cur->next;
    }
    copy->size = list->size;
    return (copy);
}
