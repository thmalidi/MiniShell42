/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:31:53 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/18 13:31:54 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_nofile(char *str)
{
	ft_dprintf(2, "%s: No such file or directory\n", str);
	g_return_value = 127;
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
	g_return_value = 126;
	return (0);
}
