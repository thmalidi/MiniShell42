NAME = minishell

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

CC = cc

HEADER = source/minishell.h

#inclure fichier .c

SRC = main.c \
source/parsing.c \
source/exit.c \
source/history.c \
source/subparsing.c \
source/subparsing_utils.c \
source/exit_utils.c \
source/srclib/ft_strjoin.c \
source/srclib/ft_strncmp.c \
source/srclib/ft_lstadd_back.c \
source/srclib/ft_lstlast.c \
source/srclib/ft_lstnew.c \
source/srclib/ft_split.c \
source/srclib/ft_strlen.c \
source/srclib/ft_substr.c \
source/srclib/ft_strdup.c \

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