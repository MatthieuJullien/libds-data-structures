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
    t_llist         *list;
    t_llist         *l2;
    t_llist         *l3;
    char            s[10][2];
    unsigned int    i;

    puts("Creation liste:");
    list = llist_create();
    infos_list(list);
    aff_list(list);
    llist_add_first(list, "1", 2);
    llist_add_last(list, "2", 2);
    llist_add_first(list, "0", 2);
    puts("\n->012 ?");
    infos_list(list);
    aff_list(list);
    llist_rm_last(list);
    llist_rm_first(list);
    llist_rm_last(list);
    llist_rm_last(list);
    llist_rm_first(list);
    puts("\n->vide ?");
    infos_list(list);
    aff_list(list);
    llist_add_last(list, "1", 2);
    llist_rm_first(list);
    llist_add_last(list, "1", 2);
    llist_add_last(list, "2", 2);
    llist_add_last(list, "3", 2);
    puts("\n->123 ?");
    infos_list(list);
    aff_list(list);
    puts("\nDestroy !");
    llist_destroy(&list);
    assert(list == NULL);

    for (i = 0; i < 10; i++)
    {
        s[i][0] = i + '0';
        s[i][1] = '\0';
    }
    list = llist_create();
    for (i = 0; i < 5; i++)
    {
        llist_add_last(list, s[i], 2);
    }
    puts("\nCopy list->l2");
    l2 = llist_copy(list);
    puts("\nlist:");
    infos_list(list);
    aff_list(list);
    puts("\nl2:");
    infos_list(l2);
    aff_list(l2);
    puts("\nMerge list et l2:");
    llist_merge(list, l2);
    infos_list(list);
    aff_list(list);
    printf("list <- 3 ? %d\n", llist_contains(list, "3", &cmp));
    printf("list <- 6 ? %d\n", llist_contains(list, "6", &cmp));
    printf("index de 3 ? %d\n", llist_indexof(list, "3", &cmp));
    printf("index de 6 ? %d\n", llist_indexof(list, "6", &cmp));
    printf("last index de 3 ? %d\n", llist_last_indexof(list, "3", &cmp));
    puts("\nAjout de x en 3");
    llist_add_at(list, "x", 2, 3);
    infos_list(list);
    aff_list(list);
    puts("\nTransformation en X de l'index 3");
    llist_set_at(list, "X", 2, 3);
    infos_list(list);
    aff_list(list);
    printf("index 3 vaut: %s\n", (char*)(llist_get_at(list, 3))->val);
    puts("Suppression de l'index 3");
    llist_rm_at(list, 3);
    infos_list(list);
    aff_list(list);
    puts("\nforeach:");
    llist_foreach(list, &f);
    puts("\n\nlist inverse:");
    llist_inverse(list);
    infos_list(list);
    aff_list(list);
    puts("\nMap list->l2");
    //llist_destroy(&l2);
    l2 = llist_map(list, &f2);
    infos_list(l2);
    aff_list(l2);
    puts("\nSort list:");
    llist_sort(list, &strcmp);
    infos_list(list);
    aff_list(list);
    puts("\ndel zeros");
    llist_rm_first(list);
    llist_rm_first(list);
    puts("\nInsert of 0 3 5 in sorted list");
    llist_sorted_insert(list, "3", 2 , &strcmp);
    llist_sorted_insert(list, "0", 2 , &strcmp);
    llist_sorted_insert(list, "5", 2 , &strcmp);
    infos_list(list);
    aff_list(list);
    puts("\nSorted merge list+list");
    llist_sorted_merge(list, list, &strcmp);
    infos_list(list);
    aff_list(list);
    puts("\nlist to array");
    void    **array;
    array = llist_to_array(list);
    i = 0;
    while (i < list->size)
    {
        printf("%s", (char *)array[i]);
        i++;
    }
    puts("\n");
    puts("\narray to l3");
    l3 = array_to_llist(array, list->size, 2);
    infos_list(l3);
    aff_list(l3);

    llist_destroy(&list);
    //llist_destroy(&l2);

    puts("\nSUCCESS !!!");
    return (0);
}
