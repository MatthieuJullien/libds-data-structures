#include "libds.h"
#include <stdlib.h>

t_llist *llist_create(void)
{
    t_llist *list;

    list = (t_llist *)malloc(sizeof(t_llist));
    if (list == NULL)
        return (NULL);
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    return (list);
}
