NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

SRC = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strcmp.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
ft_putchar_fdd.c \
ft_putnbr_base.c \
ft_putnbr_fdd.c \
ft_putnbr_l.c \
ft_putstr_fdd.c \
ft_strlen.c \
nbrlen_l.c \
nbrlen.c \
nbrlen16.c \
puthexaP.c \
treat_s.c \
treat_u.c \
treat_xX.c \
ft_printf.c \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \
get_next_line.c \
get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c Makefile $(HEADER)
	$(CC) $(FLAGS) -o $@ -c $< -I ./
	
clean:
	rm -f $(OBJ) $(OBJ_BNS)	
fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY : all clean fclean re
