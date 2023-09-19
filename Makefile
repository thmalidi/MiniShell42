# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2023/09/19 12:53:57 by tmalidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




include config/sources.mk
include config/headers.mk

#--variables-------------------------------------------------------------------#

NAME            =       minishell
DEBUG           =       no

#--includes & libraries--------------------------------------------------------#

INC_DIR         =       include
LIBFT_DIR       =       source/libft
LIBFT_HEAD		=		$(LIBFT_DIR)/header

#--sources & objects-----------------------------------------------------------#

SRC_DIR         =       source
OBJ_DIR         =       .objs/

#--flags-----------------------------------------------------------------------#

CFLAGS          =       -g3 -Wall -Wextra -Werror -I $(LIBFT_HEAD) -I $(INC_DIR)

#--debug flags--------------------------------------------------------#

DFLAGS          =       -g3 -fsanitize=address

ifeq ($(DEBUG), yes)
CFLAGS          +=      $(DFLAGS)
endif

#--libs------------------------------------------------------------------------#

LIBFT   =       $(LIBFT_DIR)/libft.a

#--objects---------------------------------------------------------------------#

OBJECTS =       $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

#--compilation rules-----------------------------------------------------------#

all:
		$(MAKE) -C ./source/libft
		$(MAKE) $(NAME) -j

$(NAME): $(OBJECTS) $(LIBFT)
		$(CC) $^ $(CFLAGS) $(LIBFT) -o $@ -lreadline

$(OBJ_DIR)/%.o: %.c $(HEADERS)
		mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

#--libs, debugs & bonus--------------------------------------------------------#

lib:
		$(MAKE) -C $(LIBFT_DIR)

debug:
		$(MAKE) re -j DEBUG=yes

#--re, clean & fclean----------------------------------------------------------#

re:
		clear
		$(MAKE) fclean
		$(MAKE) -j all

clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		$(RM) -rf $(OBJ_DIR)
		$(RM) $(NAME)

fclean:
		clear
		$(MAKE) clean
		$(MAKE) -C $(LIBFT_DIR) fclean

#--PHONY-----------------------------------------------------------------------#

.PHONY: all lib debug re clean fclean
