/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:56:51 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/01 14:27:28 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	error_manager(char *str, int error_id)
{
	const t_errors	tab_errors[] = {&error_nofile, &error_isdir, &error_notdir, \
									&error_cmd, &error_perm, &error_syntax, \
									&error_identifier, &error_args, &error_malloc, \
									&error_option};

	return((*tab_errors[error_id])(str));
}

int	error_nofile(char *str)
{
	ft_dprintf(2, "%s: No such file or directory\n", str);
	g_return_value = 1;
	return (0);
}

int	error_isdir(char *str)
{
	ft_dprintf(2, "%s: Is a directory\n", str);
	g_return_value = 126;
	return (0);
}

int	error_notdir(char *str)
{
	ft_dprintf(2, "%s: Not a directory\n", str);
	g_return_value = 1;
	return (0);
}

int	error_cmd(char *str)
{
	ft_dprintf(2, "%s: command not found\n", str);
	g_return_value = 127;
	return (0);
}

int	error_perm(char *str)
{
	ft_dprintf(2, "%s: Permission denied\n", str);
	g_return_value = 1;
	return (0);
}

int	error_syntax(char *str)
{
	ft_dprintf(2, "syntax error near expected token \'%s\'\n", str);
	g_return_value = 2;
	return (0);
}

int	error_identifier(char *str)
{
	ft_dprintf(2, "%s: not a valid identifier\n", str);
	g_return_value = 1;
	return (0);
}

int	error_args(char *str)
{
	ft_dprintf(2, "%s: too many arguments\n", str);
	g_return_value = 1;
	return (0);
}

int	error_malloc(char *str)
{
	ft_dprintf(2, "malloc failed in %s\n", str);
	g_return_value = -1;
	return (0);
}

int	error_option(char *str)
{
	ft_dprintf(2, "%s: invalid option\n", str);
	g_return_value = 2;
	return (0);
}
