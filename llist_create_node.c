#include "libds.h"
#include <stdlib.h>

t_llnode    *llist_create_node(const void *val, size_t val_size)
{
    t_llnode    *new;

    new = (t_llnode *)malloc(sizeof(t_llnode));
    if (new == NULL)
        return (NULL);
    new->val = (void *)malloc(val_size);
    if (new->val == NULL)
        return (NULL);
    memcpy(new->val, val, val_size);
    new->val_size = val_size;
    new->next = NULL;
    return (new);
}
