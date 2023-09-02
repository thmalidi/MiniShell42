/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:04:31 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/02 09:05:30 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Parsing similaire a export ?
*/


int	unset_b(t_datalist *data, t_env **env)
{
	int	i;

	if (is_an_option(data->args) == YES)
		return (error_manager("unset", OPTION), g_return_value);
	i = 0;
	while ((data->args)[++i])
	{
		if (check_var(data->args[1], "unset") < 0)
			continue;
		else
			rm_from_env(env, data->args[1]);
	}
	return (0);
}
