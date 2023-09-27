/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:12:22 by tmalidi           #+#    #+#             */
/*   Updated: 2023/09/27 15:15:17 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	between(char *str, int range)
{
	int	bool;
	int	i;

	bool = 0;
	i = 0;
	while (i < range)
	{
		if (str[i] == 34 || str[i] == 39)
		{
			bool = str[i];
			i++;
			while (i < range && str[i] != bool)
				i++;
			if (range == i)
			{
				if (str[i] == bool)
					return (1);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	replace(char *str, char c, int i)
{
	while (str[i] && str[i] != c)
	{
		if (str[i] == ' ')
			str[i] = 1;
		i++;
	}
	return (i + 1);
}

void	quote_splite(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != 39 && str[i] != 34)
			i++;
		if (str[i])
			i = replace(str, str[i], i + 1);
	}
}

void	clean_str(char *str, int v)
{
	int	i;

	i = v;
	if (!str)
		return ;
	while (str[i] && str[i + 1])
	{
		if (v == 1 && str[i] == 1)
			str[i] = ' ';
		else if (v == 0 && str[i] == 1)
			str[i] = '\'';
		else if (v == 0 && str[i] == 2)
			str[i] = '\"';
		else if (v == 1 && str[i] == 3)
			str[i] = '|';
		else if (v == 0 && str[i] == 4)
			str[i] = '<';
		else if (v == 0 && str[i] == 5)
			str[i] = '>';
		i++;
	}
}

char	*end_clean(char *str, t_element *e)
{
	char	*dup;
	char	*tmp;
	char	**tab;

	tmp = ft_strdup(prepare_string(str));
	free(str);
	tab = ft_split(tmp, 34);
	if (!tab[0])
		return (free(tab), free(tmp), e->type = 0, "\0");
	free(tmp);
	dup = join_tab(tab, 0);
	free_tab(tab);
	tab = ft_split(dup, 39);
	if (!tab[0])
		return (free(tab), free(dup), e->type = 0, "\0");
	free(dup);
	tmp = join_tab(tab, 0);
	clean_str(tmp, 0);
	ending(tmp);
	return (free_tab(tab), tmp);
}
