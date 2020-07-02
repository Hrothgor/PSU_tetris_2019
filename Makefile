##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make build
##

SRC	=	*.c\
		lib/my/*.c\

NAME	=	tetris

ERROR = -W -Wall -Wextra

all:
	gcc -o $(NAME) -g3 $(SRC) $(ERROR) -lm -Wno-unused-value -Wno-unused-parameter -lncurses
clean:
	rm -f $(CRITO) $(CRITA) unit-tests

fclean:
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit-tests ./lib/my/*.c ./tests/*.c $(SRC) -lcriterion --coverage
	./unit-tests
