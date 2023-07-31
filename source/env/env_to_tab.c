/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:14:47 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/31 07:43:03 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int	env_len(t_env *env)
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

char	**env_to_tab(t_env *env)
{
	t_env	*tmp;
	char	*line;
	char	**tab;
	int		i;
	
	if (!env)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (env_len(env) + 1));
	if (!tab)
		return (NULL);
	tmp = env;
	i = 0;
	while (tmp)
	{
		line = ft_strjoin(env->var, "=");
		if (!line)
			// Free tab et return 
		tab[i] = ft_strjoin(line, env->value);
		if (!tab[i])
			// Free tab et return
		free(line); // A check ...
	}
	tab[i + 1] = NULL;
	return (tab);
}
