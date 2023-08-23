/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:04:16 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/23 15:51:43 by hgeffroy         ###   ########.fr       */
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
			return (ft_dprintf(2, "syntax error near expected token \'%c\'\n", arg[i]), -1);
	}
	i = -1;
	while (arg[++i])
	{
		if (ft_isalpha(arg[i]))
			return (ft_dprintf(2, "exit: %s: numeric argument required\n", arg), 2);
	}
	return (ft_atoi(arg));
}

int	exit_b(t_datalist *data, t_env **env)
{
	int	shouldexit;
	
	(void)env;
	if (len_tab(data->args) > 2)
		return (printf("exit: too many arguments\n"), 1);
	if (len_tab(data->args) < 2)
		exit (0);
	shouldexit = should_exit((data->args)[1]);
	if (shouldexit == -1)
	{
		return_value = 2;
		return (shouldexit);
	}
	else
	{
		return_value = shouldexit;
		exit (return_value % 256);
	}
}
