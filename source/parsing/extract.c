/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:56:55 by tmalidi           #+#    #+#             */
/*   Updated: 2023/09/28 11:18:47 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cp_tab(char **tab)
{
	char	**new;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	init_elm(t_extract *elm, char *str)
{
	elm->tab = NULL;
	elm->tab = malloc(sizeof(char *) * (count_var(str) + 1));
	if (!elm->tab)
		return ;
	elm->i = 0;
	elm->c = 0;
}

void	extract_process(t_extract *elm, char *str)
{
	while (str[elm->i])
	{
		if (str[elm->i] == '$')
		{
			elm->j = elm->i + 1;
			if (ft_isalnum(str[elm->j]))
			{
				while (str[elm->j] && ft_isalnum(str[elm->j]))
					elm->j++;
			}
			else if (str[elm->j] == 34 || str[elm->j] == 39)
			{
				elm->tmp = ft_split(str, str[elm->j]);
				elm->tab[elm->c++] = join_tab(elm->tmp + 1, 0);
				free_tab(elm->tmp);
			}
			if (str[elm->j] == '?')
				elm->j++;
			if (elm->j - elm->i != 1)
				elm->tab[elm->c++] = ft_substr(str, elm->i, elm->j - elm->i);
		}
		elm->i++;
	}
}

char	**extract_var(char *str)
{
	t_extract	*elm;
	char		**final;

	elm = malloc(sizeof(t_extract));
	init_elm(elm, str);
	extract_process(elm, str);
	elm->tab[elm->c] = NULL;
	final = cp_tab(elm->tab);
	return (free_tab(elm->tab), free(elm), final);
}
