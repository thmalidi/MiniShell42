/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:36:13 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/19 08:36:15 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/wait.h>
# include <errno.h>

# include "libft.h"
# include "errors.h"
# include "env.h"
# include "parsing.h"
# include "builtins.h"
# include "exec.h"

enum	e_yesno
{
	YES	=	0,
	NO	=	1
};

extern int	g_return_value;

#endif