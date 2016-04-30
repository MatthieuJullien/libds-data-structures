#include "libds.h"

t_llist *llist_map(t_llist *list, t_llnode *(*f)(t_llnode *))
{
    t_llnode    *cur;
    t_llnode    *new_node;
    t_llist     *new_list;

    if (list == NULL || f == NULL)
        return (NULL);
    cur = list->first;
    new_list = llist_create();
    if (new_list == NULL)
        return (NULL);
    while (cur)
    {
        new_node = f(cur);
        llist_add_last(new_list, new_node->val, new_node->val_size);
        cur = cur->next;
    }
    return (new_list);
}
