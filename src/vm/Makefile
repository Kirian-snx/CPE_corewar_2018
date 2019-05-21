##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## File that compiles
##

SRC	=	lib/my_strcmp.c \
		lib/my_strcpy.c \
		lib/my_strlen.c \
		lib/my_strstr.c \
		lib/my_str_isnum.c \
		lib/my_getnbr.c \
		parsing.c \
		help.c \
		dump.c \
		vm.c\
		corewar.c \

OBJ 	= 	$(SRC:.c=.o)

RM	=	rm -f

CC	=	gcc

CFLAGS	=	-W -Wall -Werror -Wextra -pedantic -g3

LFLAGS  =	-I./include

NAME	=	corewar

CC = gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
	cp $(NAME) ../..
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
	$(RM) ../../$(NAME)
re: 	fclean all


