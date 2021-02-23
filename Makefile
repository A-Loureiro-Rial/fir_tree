SRC	=	my_tree.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	LaunchMe

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) && rm -f *~

fclean:
	rm -f $(NAME)

re:
	fclean all
