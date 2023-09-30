/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:03:17 by tmalidi           #+#    #+#             */
/*   Updated: 2023/09/29 09:22:28 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	interpreted(char *str, int range)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (i < range)
	{
		if (str[i] == 39 && between(str, i))
			q++;
		i++;
	}
	if (q % 2 == 0)
		return (1);
	return (0);
}

char	*make_str(char **tab)
{
	int		i;
	char	*final;
	char	*tmp;

	i = 0;
	final = malloc(sizeof(char));
	if (!final)
		return (NULL);
	final[0] = '\0';
	while (tab[i])
	{
		tmp = ft_strjoin(final, " ");
		free(final);
		final = ft_strjoin(tmp, tab[i++]);
		free(tmp);
	}
	return (final);
}

char	*mod_env(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == ':')
		{
			free(tab[i]);
			tab[i] = ft_strdup("YES");
		}
		i++;
	}
	return (make_str(tab));
}

char	*expand(char *str, t_env **env)
{
	char	*final;
	char	**tab;
	char	*tmp;
	int		i;

	i = 0;
	tab = init(str);
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		if (i != 0 && (!ft_strcmp(tab[i - 1], "<")
				|| !ft_strcmp(tab[i - 1], ">>")
				|| !ft_strcmp(tab[i - 1], ">")) && tab[i][0] == '$'
				&& !get_value_env(*env, tab[i] + 1))
			return (free_tab(tab), ft_strdup("\6\0"));
		if (i != 0 && !ft_strcmp(tab[i - 1], "<<"))
			tab[i] = tab[i];
		else
			tab[i] = expand_process(tab[i], *env);
		i++;
	}
	tmp = join_tab(tab, 1);
	final = ft_strtrim(tmp, " ");
	return (free_tab(tab), free(tmp), final);
}
