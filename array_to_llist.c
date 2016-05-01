#include "libds.h"

t_llist     *array_to_llist(void **array, size_t size, size_t val_size)
{
    t_llist     *list;
    size_t      i;

    llist_create(&list);
    if (list == NULL)
        return (NULL);
    i = 0;
    while (i < size)
    {
        llist_add_last(list, array[i], val_size);
        i++;
    }
    return (list);
}
