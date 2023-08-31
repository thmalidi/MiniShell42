/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:04:16 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/31 15:42:57 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Si trop d'arguments, on exit pas et sortie 1.
Si parenthese dans l'arg, unexpected token et on exit pas et sortie 2 !
Sinon on exit bien mais "bash: exit: str: numeric argument required" et sortie 2
*/

/*
Retourne la valeur de sortie si on doit exit, -1 sinon.
*/
int	should_exit(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '(' || arg[i] == ')')
			return (error_manager(ft_strndup(&arg[i], 1), SYNTAX), -1); // Ca doit leak ca !
	}
	i = -1;
	while (arg[++i])
	{
		if (ft_isalpha(arg[i]))
		{
			g_return_value = 2;
			return (ft_dprintf(2, "exit: %s: numeric argument required\n", arg), 2);
		}
	}
	return (ft_atoi(arg));
}

int	exit_b(t_datalist *data, t_env **env)
{
	int	shouldexit;
	
	(void)env;
	if (data->args[1] && ft_isstrdigit(data->args[1]) < 0)
	{
		g_return_value = 2;
		return (ft_dprintf(2, "exit: %s: numeric argument required\n", data->args[1]), 2);
	}
	if (len_tab(data->args) > 2)
		return (error_manager("exit", NBARGS), g_return_value);
	if (len_tab(data->args) < 2)
		exit (0);
	shouldexit = should_exit((data->args)[1]);
	if (shouldexit == -1)
	{
		g_return_value = 2;
		return (shouldexit);
	}
	else
	{
		g_return_value = shouldexit % 256;
		exit(g_return_value);
	}
}
