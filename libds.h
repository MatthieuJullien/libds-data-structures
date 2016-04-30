#ifndef LIBDS_H /* data structures */
#define LIBDS_H
#include <string.h>

typedef struct      s_llist
{
    size_t          size;
    struct s_llnode *first;
    struct s_llnode *last;
}                   t_llist;

typedef struct      s_llnode
{
    void            *val;
    size_t          val_size;
    struct s_llnode *next;
}                   t_llnode;

/* linked list */
t_llist     *llist_create(void);
t_llnode    *llist_create_node(const void *val, size_t val_size);
void        llist_add_first(t_llist *list, const void *val, size_t val_size);
void        llist_rm_first(t_llist *list);
void        llist_add_last(t_llist *list, const void *val, size_t val_size);
void        llist_rm_last(t_llist *list);
void        llist_destroy_node(t_llnode **node);
void        llist_destroy(t_llist **list);
int         llist_contains(t_llist *list, const void *val, int (*cmp)());
int         llist_indexof(t_llist *list, const void *val, int (*cmp)());
int         llist_last_indexof(t_llist *list, const void *val, int (*cmp)());
t_llist     *llist_copy(t_llist *list);
void        llist_merge(t_llist *list1, t_llist *list2);
int         llist_add_at(t_llist *list, void *val, size_t val_size,
        unsigned int index);
t_llnode    *llist_get_at(t_llist *list, unsigned int index);
void        llist_rm_at(t_llist *list, unsigned int index);
void        llist_set_at(t_llist *list, void *val, size_t val_size, 
        unsigned int index);
void        llist_foreach(t_llist *list, void (*f)(void *));
void        llist_inverse(t_llist *list);
t_llist     *llist_map(t_llist *list, t_llnode *(*f)(t_llnode *));

void        llist_sort(t_llist *list, int (*cmp)());
void        llist_sorted_insert(t_llist *list, void *val, size_t val_size, 
        int (*cmp)());
void        llist_sorted_merge(t_llist *list1, t_llist *list2, int (*cmp)());
void        **llist_to_array(t_llist *list);

t_llist     *array_to_llist(void **array, size_t size, size_t val_size);

/* double linked list */
/* set */
/* whatever ... */

#endif  /* LIBDS_H */
