#include "libds.h"

void    llist_foreach(t_llist *list, void(*f)(void *))
{
    t_llnode    *cur;

    if (list && f)
    {
        cur = list->first;
        while (cur)
        {
            f(cur->val);
            cur = cur->next;
        }
    }
}
