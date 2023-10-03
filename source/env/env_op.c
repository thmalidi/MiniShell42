/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:29:34 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/03 10:40:52 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_to_env(t_env **env, char *var, char *value)
{
	t_env	*new;
	t_env	*temp;

	new = check_add_env(env, var, value);
	if (!(*env))
	{
		*env = new;
		return (0);
	}
	temp = *env;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (0);
}

int	rm_from_env(t_env **env, char *var_to_rm)
{
	t_env	*tmp1;
	t_env	*tmp2;

	if (!env || !(*env))
		return (-1);
	if (ft_strcmp((*env)->var, var_to_rm) == 0)
	{
		tmp1 = *env;
		*env = (*env)->next;
		env_free_elt(tmp1);
		return (0);
	}
	tmp2 = env_lfvar(*env, var_to_rm);
	if (!tmp2)
		return (0);
	tmp1 = tmp2->next;
	tmp2->next = tmp1->next;
	env_free_elt(tmp1);
	return (0);
}

int	set_value_env(t_env **env, char *var_to_set, char *value)
{
	t_env	*tmp1;

	tmp1 = env_lfvar(*env, var_to_set);
	if (!tmp1 && strcmp((*env)->var, var_to_set))
		return (-1);
	else if (!tmp1)
	{
		free((*env)->value);
		(*env)->value = ft_strdup(value);
		if (!(*env)->value)
			free_env_and_exit(env);
	}
	else
	{
		tmp1 = tmp1->next;
		free(tmp1->value);
		tmp1->value = ft_strdup(value);
		if (!tmp1->value)
			free_env_and_exit(env);
	}
	return (0);
}

char	*get_value_env(t_env *env, char *var)
{
	t_env	*tmp;

	tmp = env_lfvar(env, var);
	if (!tmp)
	{
		if (env->var == var)
			return (env->value);
		else
			return (NULL);
	}
	return (tmp->next->value);
}
