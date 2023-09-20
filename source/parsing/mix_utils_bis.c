/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_utils_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:56:31 by tmalidi           #+#    #+#             */
/*   Updated: 2023/09/20 13:42:09 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	only(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] != '<' && str[i] != '>')
			return (0);
		i++;
	}
	return (1);
}

char	*free_trim(char *str)
{
	char *trim;
	trim = ft_strtrim(str, "\"");
	return (free(str), trim);
}

int	potential_error(t_element	*etmp, t_big_list	*tmp)
{
	(void) tmp;
	
	if (etmp->type == 1 || etmp->type == 2 || etmp->type == 3
			|| etmp->type == 4 || etmp->type == 6)
	{
			if (etmp->previous && (etmp->previous->type == 1 || etmp->previous->type == 2 || etmp->previous->type == 3
					|| etmp->previous->type == 4))
			{
				return (error_manager(etmp->str, SYNTAX), 0);
			}
			if (!etmp->next)
			{
				return (error_manager("\\n", SYNTAX), 0);
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
