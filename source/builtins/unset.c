/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:04:31 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/09 14:39:41 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset(t_datalist *data ,t_env *env) // Si on a plusieurs var allo !!
{
	int	i;
	
	i = -1;
	while ((data->args)[++i])
	{
		if (check_var(var_to_unset) < 0)
			/*print une erreur*/;
		else
			rm_from_env(&env, var_to_unset);
	}
	return (0);
}
