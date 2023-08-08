# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 14:42:36 by hgeffroy          #+#    #+#              #
#    Updated: 2023/08/07 14:52:37 by hgeffroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	source/main.c \
			source/parsing/parsing.c \
			source/parsing/exit.c \
			source/parsing/history.c \
			source/parsing/subparsing.c \
			source/parsing/subparsing_utils.c \
			source/parsing/exit_utils.c \
			source/srclib/ft_strjoin.c \
			source/srclib/ft_strncmp.c \
			source/srclib/ft_lstadd_back.c \
			source/srclib/ft_lstlast.c \
			source/srclib/ft_lstnew.c \
			source/srclib/ft_split.c \
			source/srclib/ft_strlen.c \
			source/srclib/ft_substr.c \
			source/srclib/ft_strdup.c \
			source/env/env_create.c \
			source/env/env_free.c \
			source/env/env_op.c \
			source/env/env_to_tab.c \
			source/env/env_utils.c \
			source/exec/exec_args.c \
			source/exec/exec_free.c \
			source/exec/exec_heredoc.c \
			source/exec/exec_init.c \
			source/exec/exec_utils.c \
			source/exec/exec.c \
			source/builtins/builtins_utils.c \
			source/builtins/export.c
			