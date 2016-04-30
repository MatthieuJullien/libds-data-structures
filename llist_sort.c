#include "libds.h"
static void swap(t_llnode *n1, t_llnode *n2);

void    llist_sort(t_llist *list, int (*cmp)())
{
    t_llnode    *cur;
    t_llnode    *nxt;
    int         isSorted;

    if (list == NULL || cmp == NULL)
        return ;
    isSorted = 0;
    while (!isSorted)
    {
        isSorted = 1;
        cur = list->first;
        nxt = cur->next;
        while (nxt)
        {
            if (cmp(cur->val, nxt->val) > 0)
            {
                swap(cur, nxt);
                isSorted = 0;
            }
            cur = cur->next;
            nxt = cur->next;
        }
    }
}

static void swap(t_llnode *n1, t_llnode *n2)
{
    void    *val_tmp;
    size_t  size_tmp;

    val_tmp = n1->val;
    n1->val = n2->val;
    n2->val = val_tmp;
    size_tmp = n1->val_size;
    n1->val_size = n2->val_size;
    n2->val_size = size_tmp;
}
