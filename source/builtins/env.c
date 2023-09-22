/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:10:58 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/22 09:05:25 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Check les eventuels arguments, je pense qu'on met juste un message d'erreur 
s'il y a des arguments.
Il ne faut pas print si les var n'ont pas de value, gere dans env_print.
*/
int	env_b(t_datalist *data, t_env **env)
{
	g_return_value = 0;
	if (len_tab(data->args) > 1)
		error_manager("env", NBARGS);
	else
		env_print(*env);
	return (g_return_value);
}
