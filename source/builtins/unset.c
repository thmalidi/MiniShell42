/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:28:05 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/23 08:00:34 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_b(t_data *data)
{
	int	i;

	g_return_value = 0;
	if (is_an_option(data->args, 0) == YES)
		return (error_manager("unset", OPTION), g_return_value);
	i = 0;
	while ((data->args)[++i])
	{
		if (check_var(data->args[i], "unset") < 0)
			break ;
		else
			rm_from_env(data->env, data->args[1]);
	}
	return (g_return_value);
}
