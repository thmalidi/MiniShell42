/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_utils_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:56:31 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/30 14:04:41 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*free_trim(char *str)
{
	char *trim;
	trim = ft_strtrim(str, "\"");
	return (free(str), trim);
}

int	potential_error(t_element	*etmp, t_big_list	*tmp)
{
	if ((etmp->type == 1 || etmp->type == 2 || etmp->type == 3
			|| etmp->type == 4) && etmp->next == NULL)
	{
		if (tmp->next == NULL)
			return (dprintf(2,"parse error near `\\n'\n"),
				g_return_value = 130, 0);
		else
			return (dprintf(2,"parse error near `|'\n"),
				g_return_value = 130, 0);
	}
	return (1);
}
