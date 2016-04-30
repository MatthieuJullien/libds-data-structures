#include "libds.h"

t_llist     *llist_merge(t_llist *list1, t_llist *list2)
{
    if (list1 == NULL || list2 == NULL)
        return (NULL);
    list1->last->next = list2->first;
    list1->last = list2->last;
    list1->size = list1->size + list2->size;
    return (list1);
}
