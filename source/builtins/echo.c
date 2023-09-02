/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:04:11 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/02 07:42:46 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	noneed_breakline(char **args)
{
	int	i;

	if (!args[1])
		return (0);
	if (ft_strncmp(args[1], "-n", 2) == 0)
	{
		i = 1;
		while (args[1][++i])
		{
			if (args[1][i] != 'n')
				return (0);
		}
		return (1);
	}
	return (0);
}

int	echo_b(t_datalist *data, t_env **env)
{
	int	breakline;
	int	i;

	(void)env;
	breakline = noneed_breakline(data->args);
	if (!(data->args) || !(data->args[0]))
		return(0);
	printf("%s", data->args[breakline + 1]);
	i = breakline + 1;
	while (data->args[++i])
		printf(" %s", data->args[i]);
	if (breakline == 0)
		printf("\n");
	g_return_value = 0;
	return (0);
}
