/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:39:03 by tmalidi           #+#    #+#             */
/*   Updated: 2023/10/01 15:22:00 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*init_final(char **tab, int s, int v, int *i)
{
	if (v == 1)
	{
		if (s)
			return (ft_strjoin(tab[0], " "));
		else
			return (ft_strdup(tab[0]));
	}
	else
	{
		if (s)
			return (ft_strjoin(tab[*i++], " "));
		else
			return (ft_strdup(""));
	}
}

char	*init_bef(char **tab, int s, int i)
{
	if (tab[0] && tab[0][0] != 6)
		return (init_final(tab, s, 1, &i));
	else
		return (ft_strdup(""));
}

char	*join_tab(char **tab, int s)
{
	char	*tmp;
	char	*final;
	int		i;

	i = 1;
	final = init_bef(tab, s, i);
	if (final && tab[i - 1])
	{
		while (tab[i])
		{
			if (tab[i][0] != 6)
			{
				tmp = ft_strjoin(final, tab[i]);
				free(final);
				if (tab[i + 1] && s)
					final = ft_strjoin(tmp, " ");
				else
					final = ft_strdup(tmp);
				free(tmp);
			}
			i++;
		}
	}
	return (final);
}
