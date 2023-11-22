##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## gcc all lib and myh
## with also a clean rule
##

SRC	=	my_main.c				\

OBJ	=	$(SRC:.c=.o)

NAME	=	setting_up

all:	fclean $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME)	$(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all