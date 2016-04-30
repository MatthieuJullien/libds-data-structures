#include "libds.h"

int     llist_contains(t_llist *list, const void *val, int(cmp)())
{
    if (llist_indexof(list, val, cmp) == -1)
        return (0);
    else
        return (1);
}
