/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:13:23 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/11 14:50:57 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Check les eventuels arguments, je pense qu'on met juste un message d'erreur 
s'il y a des arguments.
Il ne faut pas print si les var n'ont pas de value !!!
*/
int	env_b(t_datalist *data, t_env **env)
{
	if (len_tab(data->args) > 1)
		printf("Env Shouldn't be ran with args\n");
	else
		env_print(*env);
	return (0);
}
