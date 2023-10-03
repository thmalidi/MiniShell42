/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:29:17 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/30 08:06:29 by hgeffroy         ###   ########.fr       */
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
		return (error_manager("get_var", MALLOC), NULL);
	ft_strlcpy(var, line, i + 1);
	var[i + 1] = '\0';
	return (var);
}

int	create_env_from_scratch(t_env **lst_env)
{
	if (add_to_env(lst_env, ft_strdup("OLDPWD"), NULL) == -2)
		return (error_manager("create_env_from_scratch", MALLOC), -1);
	if (add_to_env(lst_env, ft_strdup("PWD"), getcwd(NULL, 0)) == -2)
		return (error_manager("create_env_from_scratch", MALLOC), -1);
	if (add_to_env(lst_env, ft_strdup("SHLVL"), ft_strdup("1")) == -2)
		return (error_manager("create_env_from_scratch", MALLOC), -1);
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
		if (g_return_value < 0)
			exit (g_return_value);
		return (lst_env);
	}
	i = -1;
	while (env[++i])
	{
		var = get_var(env[i]);
		add_to_env(&lst_env, ft_strdup(var), ft_strdup(getenv(var)));
		free(var);
	}
	return (lst_env);
}
