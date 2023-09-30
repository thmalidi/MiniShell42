/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:29:17 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/29 08:28:57 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_var(char *line);

static char	*get_var(char *line)
{
	int		i;
	char	*var;

	i = 0;
	while (line[i] != '=')
		i++;
	var = (char *)malloc(sizeof(char) * (i + 3));
	if (!var)
		return (NULL);
	ft_strlcpy(var, line, i + 1);
	var[i + 1] = '\0';
	return (var);
}

int	create_env_from_scratch(t_env **lst_env)
{
	add_to_env(lst_env, ft_strdup("OLDPWD"), NULL);
	add_to_env(lst_env, ft_strdup("PWD"), getcwd(NULL, 0));
	add_to_env(lst_env, ft_strdup("SHLVL"), ft_strdup("1"));
	return (0);
}

t_env	*create_env(char **env)
{
	int		i;
	char	*var;
	t_env	*lst_env;

	lst_env = NULL;
	if (!env[0])
	{
		create_env_from_scratch(&lst_env);
		return (lst_env);
	}
	i = -1;
	while (env[++i])
	{
		var = get_var(env[i]);
		if (!var)
			return (free_env(lst_env), free(var), NULL);
		if (add_to_env(&lst_env, ft_strdup(var), ft_strdup(getenv(var))))
			return (free_env(lst_env), free(var), NULL);
		free(var);
	}
	return (lst_env);
}
