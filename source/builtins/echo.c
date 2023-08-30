/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:04:11 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/30 13:37:46 by hgeffroy         ###   ########.fr       */
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
	i = breakline;
	while (data->args[++i])
		printf("%s ", data->args[i]);
	if (breakline == 0)
		printf("\n");
	return (0);
}
