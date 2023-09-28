/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:03:17 by tmalidi           #+#    #+#             */
/*   Updated: 2023/09/28 09:39:52 by tmalidi          ###   ########.fr       */
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

/*char	*join_tab(char **tab, int s)
{
	char	*tmp;
	char	*final;
	int		i;

	i = 1;
	if (tab[0] && tab[0][0] != 6)
	{
		if (s)
			final = ft_strjoin(tab[0], " ");
		else
			final = ft_strdup(tab[0]);
	}
	else
	{
		if (s)
			final = ft_strjoin(tab[i++], " ");
		else
			final = ft_strdup("");
	}
	if (tab[i - 1])
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
}*/

char	*expand(char *str, t_env **env)
{
	char	*final;
	char	**tab;
	char	*tmp;
	int		i;

	i = 0;
	tab = init(str);
	while (tab[i])
	{
		if (i != 0 && (!ft_strcmp(tab[i - 1], "<")
				|| !ft_strcmp(tab[i - 1], ">>")
				|| !ft_strcmp(tab[i - 1], ">")) && tab[i][0] == '$'
				&& !get_value_env(*env, tab[i] + 1))
			return (error_manager(tab[i], AMBIGUOUS), NULL);
		if (i != 0 && !ft_strcmp(tab[i - 1], "<<"))
			tab[i] = tab[i];
		else
			tab[i] = expand_process(tab[i], *env);
		//printf("%d{-\n",tab[i][0]);
		i++;
	}
	tmp = join_tab(tab, 1);
	final = ft_strtrim(tmp, " ");
	free_tab(tab);
	return (free(tmp), final);
}
