NAME = minishell

FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

CC = cc

HEADER = minishell.h

#inclure fichier .c
SRC = parsing.c \

OBJ = $(SRC:.c=.o)

LIB_PATH = libft/

LIB = $(addprefix $(LIB_PATH), libft.a)

all: lib
	make $(NAME)

lib :
	make -C $(LIB_PATH)

$(NAME): $(OBJ) 
	$(CC)  $(OBJ) $(FLAGS) -o $(NAME) $(LIB) -L/usr/include/readline/readline.h -lreadline

%.o: %.c Makefile $(HEADER)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean
	$(MAKE) all

.PHONY : all clean fclean re