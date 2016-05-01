#include "libds.h"

int     llist_add_nodup(t_llist *list, void *val, size_t val_size, int (*cmp)())
{
    if (!llist_contains(list, val, cmp))
    {
        llist_add_last(list, val, val_size);
        return (1);
    }
    return (0);
}
