/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:46:36 by tmalidi           #+#    #+#             */
/*   Updated: 2023/09/21 16:04:21 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*change(char *str, char *final, t_env *env, char *rv)
{
	if (!ft_strncmp("$?", str, ft_strlen(str)))
		return (rp_env(final, str, rv));
	else
		return (rp_env(final, str, get_value_env(env, str + 1)));
}

void	ending(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == 1)
			tmp[i] = '\'';
		if (tmp[i] == 2)
			tmp[i] = '\"';
		if (tmp[i] == 4)
			tmp[i] = '<';
		if (tmp[i] == 5)
			tmp[i] = '>';
		i++;
	}
}
