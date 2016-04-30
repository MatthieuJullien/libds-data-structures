#include "libds.h"
#include <stdlib.h>

void    llist_add_last(t_llist *list, const void *val, size_t val_size)
{
    t_llnode    *node;

    node = llist_create_node(val, val_size);
    if (list->size > 0)
        list->last->next = node;
    else
        list->first = node;
    list->last = node;
    list->size++;
}
