#include "libds.h"
#include <stdlib.h>

void    llist_destroy(t_llist **list)
{
    t_llnode    *cur;
    t_llnode    *nxt;

    if (list && *list)
    {
        cur = (*list)->first;
        while (cur)
        {
            nxt = cur->next;
            llist_destroy_node(&cur);
            cur = nxt;
        }
        free(*list);
        *list = NULL;
    }
}
