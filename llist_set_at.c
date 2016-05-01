#include "libds.h"
#include <stdlib.h>

void    llist_set_at(t_llist *list, void *val, size_t val_size, 
        unsigned int index)
{
    t_llnode    *cur;

    if (index >= list->size)
        return ;
    cur = list->first;
    while (index > 0)
    {
        cur = cur->next;
        index--;
    }
    if (cur->val)
        free(cur->val);
    cur->val = (void *)malloc(val_size);
    if (cur->val == NULL)
       return ;
    memcpy(cur->val, val, val_size); 
    cur->val_size = val_size;
}
