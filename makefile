##
## EPITECH PROJECT, 2018
## CPE_dante_2018
## File description:
## makefile
##

# SRCS	=	
# OBJ     =	$(SRCS:.c=.o)

RM	=	rm -f

all:	vm asm 

vm:
	make -C src/vm
asm:
	make -C src/asm
clean:
	$(RM) $(OBJ)
	make -C src/vm clean
	make -C src/asm clean
fclean:	clean
	make -C src/vm fclean
	make -C src/asm fclean
re:	fclean all
