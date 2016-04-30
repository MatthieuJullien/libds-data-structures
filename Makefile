NAME	=	libds.a
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRC	=	llist_create.c		\
		llist_create_node.c	\
		llist_add_first.c	\
		llist_rm_first.c	\
		llist_add_last.c	\
		llist_rm_last.c		\
		llist_destroy_node.c	\
		llist_destroy.c		\
		llist_contains.c	\
		llist_indexof.c		\
		llist_last_indexof.c	\
		llist_copy.c		\
		llist_merge.c		\
		llist_add_at.c		\
		llist_get_at.c		\
		llist_rm_at.c		\
		llist_set_at.c		\
		llist_foreach.c		\
		llist_inverse.c		\
		llist_map.c		\
		llist_sort.c		\
		llist_sorted_insert.c	\
		llist_sorted_merge.c	\
		llist_to_array.c	\
		array_to_llist.c			
				
OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
