#include "libds.h"

t_llnode    *llist_get_at(t_llist *list, unsigned int index)
{
    t_llnode    *cur;

    if (index > list->size)
        return (NULL);
    cur = list->first;
    while (index > 0 && cur != NULL)
    {
        cur = cur->next;
        index--;
    }
    return (cur);
}
