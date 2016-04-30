#include <stdlib.h>
#include "libds.h"

void    llist_destroy_node(t_llnode **node)
{
    if (node && *node)
    {
        free((*node)->val);
        free(*node);
        *node = NULL;
    }
}
