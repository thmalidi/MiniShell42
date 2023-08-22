/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:04:22 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/22 17:36:59 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//tmalidi

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/wait.h>

# include "libft.h"
# include "env.h"
# include "parsing.h"
# include "builtins.h"
# include "exec.h"

extern int return_value;

#endif