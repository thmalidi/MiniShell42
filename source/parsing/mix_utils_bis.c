/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_utils_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:56:31 by tmalidi           #+#    #+#             */
/*   Updated: 2023/09/19 15:57:45 by tmalidi          ###   ########.fr       */
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
	(void) tmp;
	if ((etmp->type == 1 || etmp->type == 2 || etmp->type == 3
			|| etmp->type == 4))
	{
			if (etmp->previous && (etmp->previous->type == 1 || etmp->previous->type == 2 || etmp->previous->type == 3
					|| etmp->previous->type == 4))
			{
				printf("passsseee\n");
				return (error_manager(etmp->str, SYNTAX),
					g_return_value = 130, 0);
			}
			if (!etmp->next)
			{
				return (error_manager("\\n", SYNTAX),
					g_return_value = 130, 0);
			}
	}
	return (1);
}

int	check_full_space(char *str)
{
	char **tab;
	int i;
	int j;
	int s;

	tab = ft_split(str, '|');
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			s = 1;
			if (tab[i][j] != ' ')
			{
				s = 0;
				break;
			}
			j++;
		}
		i++;
		if (s == 1)
			return (free_tab(tab), 1);
	}
	return (free_tab(tab), 0);
}
