/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:04:31 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/11 15:27:39 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_b(t_datalist *data, t_env **env)
{
	int	i;

	i = -1;
	while ((data->args)[++i])
	{
		if (check_var(data->args[1]) < 0)
			printf("Une erreur");
		else
			rm_from_env(env, data->args[1]);
	}
	return (0);
}
