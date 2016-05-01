#include "libds.h"
#include <stdlib.h>

void    llist_merge(t_llist *list1, t_llist *list2)
{
    t_llist     *copy_list2;

    if (list1 == NULL || list2 == NULL)
        return ;
    copy_list2 = llist_copy(list1);
    if (copy_list2 == NULL)
        return ;
    list1->last->next = copy_list2->first;
    list1->last = copy_list2->last;
    list1->size = list1->size + copy_list2->size;
    free(copy_list2);
}
