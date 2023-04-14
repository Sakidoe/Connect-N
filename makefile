NAME = connectn.out
SRCS = main.c board.c move.c win.c
FLAGS = -Wall -Werror

all:
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I .
	
clean:
	rm -f $(NAME)
