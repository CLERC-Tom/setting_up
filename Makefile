##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## gcc all lib and myh
## with also a clean rule
##

SRC	=   my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_strlen.c			\
		my_strcmp.c 	\
		my_printf.c			\
		error.c \
		algo2.c \
		parcours.c  \
		my_strcpy.c \
		verif.c  \
		my_main.c 		\


OBJ	=	$(SRC:.c=.o)

NAME	=	setting_up

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME)	$(OBJ) -g3

%.o: %.c
	gcc -g -c $< -o $@

test:
	echo $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f libmy.a

re:	fclean all
