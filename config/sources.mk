# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 14:42:36 by hgeffroy          #+#    #+#              #
#    Updated: 2023/08/17 09:22:49 by hgeffroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	source/main.c \
			source/parsing/parsing.c \
			source/parsing/parsing_utils.c \
			source/parsing/exit.c \
			source/parsing/history.c \
			source/parsing/subparsing.c \
			source/parsing/subparsing_utils.c \
			source/parsing/exit_utils.c \
			source/parsing/quote_tools.c \
			source/parsing/expand.c \
			source/parsing/expand_utils.c \
			source/srclib/ft_lstadd_back.c \
			source/srclib/ft_lstlast.c \
			source/srclib/ft_lstnew.c \
			source/env/env_create.c \
			source/env/env_free.c \
			source/env/env_op.c \
			source/env/env_to_tab.c \
			source/env/env_utils.c \
			source/exec/exec_cmd.c \
			source/exec/exec_cmd_utils.c \
			source/exec/exec_free.c \
			source/exec/exec_heredoc.c \
			source/exec/exec_init.c \
			source/exec/exec_utils.c \
			source/exec/exec.c \
			source/exec/signals.c \
			source/builtins/builtins_utils.c \
			source/builtins/cd.c \
			source/builtins/echo.c \
			source/builtins/env.c \
			source/builtins/exit.c \
			source/builtins/export.c \
			source/builtins/export_parsing.c \
			source/builtins/pwd.c \
			source/builtins/unset.c
			