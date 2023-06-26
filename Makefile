NAME = minishell

FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

CC = cc

HEADER = minishell.h

#inclure fichier .c
SRC = 

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) 
	$(CC)  $(OBJ) $(FLAGS) -o $(NAME)

%.o: %.c Makefile $(HEADER)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY : all clean fclean re