##
## EPITECH PROJECT, 2020
## makefile
## File description:
## .o
##

SRC	=	src/malloc.c	\
		src/calloc.c	\
		src/realloc.c	\
		src/reallocarray.c	\
		src/free.c	\
		src/utils/alloc_utils.c	\
		src/utils/free_utils.c	\
		src/utils/my_memcpy.c

NAME	=	libmy_malloc.so

OBJS	=	$(SRC:.c=.o)

FLAGS	=	-Wall -Wextra -Wno-deprecated -Werror

LIB		=

HEAD	=	-I./include

all:	$(NAME)

$(NAME):
	@gcc -fPIC -shared -o $(NAME) $(LIB) $(FLAGS) $(HEAD) $(SRC)

clean:
	@rm -rf $(OBJS)
fclean:		clean
	@rm -rf $(NAME)

re:	fclean all
