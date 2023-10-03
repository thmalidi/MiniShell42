/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:29:24 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/03 08:08:35 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_free_elt(t_env *elt)
{
	if (!elt)
		return ;
	if (elt->var)
		free(elt->var);
	if (elt->value)
		free(elt->value);
	free(elt);
}

void	free_env(t_env *env)
{
	t_env	*tmp1;
	t_env	*tmp2;

	if (!env)
		return ;
	tmp2 = env;
	tmp1 = env->next;
	while (tmp1)
	{
		env_free_elt(tmp2);
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	env_free_elt(tmp2);
}

t_env	*check_add_env(t_env **env, char *var, char *value)
{
	t_env	*new;

	if (!var)
	{
		error_manager("add_to_env", MALLOC);
		free_env(*env);
		if (var)
			free(var);
		if (value)
			free(value);
		exit (-1);
	}
	new = env_newelt(var, value);
	if (!new)
	{
		error_manager("add_to_env", MALLOC);
		free_env(*env);
		free(var);
		if (value)
			free(value);
		exit (-1);
	}
	return (new);
}

int	free_env_and_exit(t_env **env)
{
	free_env(*env);
	error_manager("set_value_env", MALLOC);
	exit(-1);
}
