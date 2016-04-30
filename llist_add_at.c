#include "libds.h"
#include <stdlib.h>

int     llist_add_at(t_llist *list, void *val, size_t val_size, 
        unsigned int index)
{
    t_llnode    *new;
    t_llnode    *prv;
    t_llnode    *cur;
    
    if (index > list->size)
        return (0);
    new = llist_create_node(val, val_size);
    if (new == NULL)
        return (0);
    prv = NULL;
    cur = list->first;
    while (index > 0 && cur != NULL)
    {
        prv = cur;
        cur = cur->next;
        index--;
    }
    if (cur == NULL)
        list->last = new;
    prv->next = new;
    new->next = cur;
    list->size++;
    return (1);
}


