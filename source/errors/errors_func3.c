/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_func3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 07:39:23 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/21 11:45:39 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_quotes(char *str)
{
	ft_dprintf(2, " unexpected EOF while looking for matching `%s'\n", str);
	g_return_value = 2;
	return (0);
}

int	error_hd(char *str)
{
	ft_dprintf(2, \
	" here-document at line 1 delimited by end-of-file (wanted `%s')\n", str);
	g_return_value = 0;
	return (0);
}

int	error_notset(char *str)
{
	ft_dprintf(2, " cd: %s not set\n", str);
	g_return_value = 1;
	return (0);
}
