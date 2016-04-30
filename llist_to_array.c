#include "libds.h"
#include <stdlib.h>

void    **llist_to_array(t_llist *list)
{
    void        **array;
    size_t      i;
    t_llnode    *cur;

    array = (void **)malloc(sizeof(void *) * list->size);
    if (array == NULL)
        return (NULL);
    i = 0;
    cur = list->first;
    while (i < list->size)
    {
        array[i] = (void *)malloc(cur->val_size);
        if (array[i] == NULL)
            return (NULL);
        memcpy(array[i], cur->val, cur->val_size);
        i++;
        cur = cur->next;
    }
    return (array);
}
