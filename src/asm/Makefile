##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC		=		gcc

CFLAGS	=		-W -Wall -Werror -Wextra -g3

RM		=		rm -f

SRC		=		op.c	\
				error_handling.c 	\
				useful_a.c	\
				useful_b.c	\
				str_to_tab.c

OBJ		=		$(SRC:.c=.o)

NAME	=		asm

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
			cp $(NAME) ../../

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			$(RM) ../../$(NAME)

re:			fclean all