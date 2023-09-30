/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:10:58 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/29 08:20:53 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_b(t_data *data)
{
	g_return_value = 0;
	if (len_tab(data->args) > 1)
		error_manager("env", NBARGS);
	else
		env_print(*data->env);
	return (g_return_value);
}
