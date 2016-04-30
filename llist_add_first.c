#include "libds.h"
#include <stdlib.h>

void    llist_add_first(t_llist *list, const void *val, size_t val_size)
{
    t_llnode    *node;

    node = llist_create_node(val, val_size);
    node->next = list->first;
    if (list->size == 0)
        list->last = node;
    list->first = node;
    list->size++;
}
