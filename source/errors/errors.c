/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:56:51 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/24 13:58:53 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_manager(char *str, int error_id)
{
	const t_errors	tab_errors[] = {&error_nofile, &error_isdir, &error_notdir, \
									&error_cmd, &error_perm, &error_syntax, \
									&error_identifier, &error_args};

	return((*tab_errors[error_id])(str));
}

int	error_nofile(char *str)
{
	ft_dprintf(2, "%s: no such file or directory\n", str);
	return_value = 127;
	return (0);
}

int	error_isdir(char *str)
{
	ft_dprintf(2, "%s: is a directory\n", str);
	return_value = 126;
	return (0);
}

int	error_notdir(char *str)
{
	ft_dprintf(2, "%s: not a directory\n", str);
	return_value = 1;
	return (0);
}

int	error_cmd(char *str)
{
	ft_dprintf(2, "%s: command not found\n", str);
	return_value = 127;
	return (0);
}

int	error_perm(char *str)
{
	ft_dprintf(2, "%s: permission denied\n", str);
	return_value = 126;
	return (0);
}

int	error_syntax(char *str)
{
	ft_dprintf(2, "syntax error near expected token \'%s\'\n", str);
	return_value = 2;
	return (0);
}

int	error_identifier(char *str)
{
	ft_dprintf(2, "%s: not a valid identifier\n", str);
	return_value = 1;
	return (0);
}

int	error_args(char *str)
{
	ft_dprintf(2, "%s: too many arguments\n", str);
	return_value = 1;
	return (0);
}
