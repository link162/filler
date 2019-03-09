NAME = sudoku
FLAGS = -Wall -Wextra -Werror
FILES = main.c
OBJECT = $(FILES:.c=.o)

$(NAME) : $(OBJECT)
	@gcc -c $(FILES)
	@gcc -o $(NAME) $(OBJECT)

all: $(NAME)

clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean clean re
