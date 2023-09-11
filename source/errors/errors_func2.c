/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:09:33 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/11 16:12:17 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

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
