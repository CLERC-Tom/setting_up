##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## gcc all lib and myh
## with also a clean rule
##

SRC	=	my_printf.c			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_strlen.c			\
		my_print_octal.c		\
		my_print_hexa.c			\
		my_print_hexa_capped.c		\
		my_print_float.c		\
		big_science_e.c			\
		science_e.c			\
		pointer.c			\
		n.c				\
		mini_printf.c			\
		cpt_nbr.c			\
		cpt_hex.c			\
		cpt_oct.c			\
		min_g.c				\
		maj_g.c				\
		my_ls.c 	\
		ls_a.c 				\
		my_strcmp.c 	\
		my_main.c 		\


OBJ	=	$(SRC:.c=.o)

NAME	=	setting_up

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME)	$(OBJ) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f libmy.a

re:	fclean all
