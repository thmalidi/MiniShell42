/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:14:47 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/11 15:34:43 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*line_var(t_env *env);

int	env_len(t_env *env)
{
	t_env	*tmp;
	int		count;

	if (!env)
		return (0);
	tmp = env;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

static char	*line_var(t_env *env)
{
	int		i;
	int		j;
	char	*line;

	line = (char *)malloc(sizeof(char) * \
	(ft_strlen(env->value) + ft_strlen(env->var) + 2));
	if (!line)
		return (NULL);
	i = -1;
	while ((env->var)[++i])
		line[i] = (env->var)[i];
	j = -1;
	line[i] = '=';
	i++;
	while ((env->value)[++j])
	{
		line[i] = (env->value)[j];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**env_to_tab(t_env *env)
{
	t_env	*tmp;
	char	**tab;
	int		i;

	if (!env)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (env_len(env) + 2));
	if (!tab)
		return (NULL);
	tmp = env;
	i = 0;
	while (tmp)
	{
		tab[i] = line_var(tmp);
		if (!tab[i])
			return (free_tab(tab), NULL);
		tmp = tmp->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
