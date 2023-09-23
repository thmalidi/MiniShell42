/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:11:45 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/23 08:08:09 by hgeffroy         ###   ########.fr       */
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
	int		i;
	char	*char_error;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '(' || arg[i] == ')')
		{
			char_error = ft_strndup(&arg[i], 1);
			error_manager(char_error, SYNTAX);
			free(char_error);
			return (-1);
		}
	}
	i = -1;
	if (ft_isstrdigit(arg) == -1)
	{
		g_return_value = 2;
		ft_dprintf(2, "exit: %s: numeric argument required\n", arg);
		return (2);
	}
	return (ft_atoi(arg));
}

int	exit_b(t_data *data)
{
	int	shouldexit;

	if (len_tab(data->args) < 2)
	{
		free_env(*data->env);
		free_data(data->head);
		exit (0);
	}
	shouldexit = should_exit((data->args)[1]);
	if (shouldexit == -1)
	{
		g_return_value = 2;
		return (shouldexit);
	}
	else if (len_tab(data->args) > 2 && shouldexit != 2)
		return (error_manager("exit", NBARGS), g_return_value);
	else
	{
		g_return_value = shouldexit % 256;
		free_env(*data->env);
		free_data(data->head);
		exit(g_return_value);
	}
}
