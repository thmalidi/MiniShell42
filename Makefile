NAME = minishell

FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

CC = cc

HEADER = minishell.h

#inclure fichier .c

SRC = parsing.c \
exit.c \
srclib/ft_lstadd_back.c \
srclib/ft_lstlast.c \
srclib/ft_lstnew.c \
srclib/ft_split.c \
srclib/ft_strlen.c \
srclib/ft_substr.c \
srclib/ft_strdup.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) 
	$(CC)  $(OBJ) $(FLAGS) -o $(NAME) -L/usr/include/readline/readline.h -lreadline

%.o: %.c Makefile $(HEADER)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY : all clean fclean re