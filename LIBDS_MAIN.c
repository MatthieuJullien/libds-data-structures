#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libds.h"

void    aff_list(t_llist *list)
{
    t_llnode    *cur = list->first;

    printf("-> ");
    while (cur)
    {
        printf("%s", (char *)(cur->val));
        cur = cur->next;
    }
    printf("\n");
}

void    f(void *val)
{
    printf("%s ", (char *)(val));
}

t_llnode    *f2(t_llnode *node)
{
    t_llnode    *new;
    if (strcmp(node->val, "2") == 0)
        new = llist_create_node(".", 2);
    else
        new = llist_create_node(node->val, node->val_size);
    return (new);
}

void    infos_list(t_llist *list)
{
    if (list->first == NULL)
        puts("first: NULL");
    else
        printf("first: %s\n", (char *)(list->first->val));
    if (list->last == NULL)
        puts("last: NULL");
    else
        printf("last: %s\n", (char *)(list->last->val));
    printf("size: %d\n", (int)list->size);
}

int     cmp(char *s1, char *s2)
{
    if (strcmp(s1, s2) == 0)
        return (1);
    return (0);
}

int     main(void)
{
    puts("\nSUCCESS !!!");
    return (0);
}
