/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:31:25 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/29 08:21:42 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_newelt(char *newvar, char *newvalue)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->var = newvar;
	new->value = newvalue;
	new->next = NULL;
	return (new);
}

t_env	*env_lfvar(t_env *env, char *lfvar)
{
	t_env	*tmp1;
	t_env	*tmp2;

	if (!env)
		return (NULL);
	tmp1 = env->next;
	tmp2 = env;
	while (tmp1)
	{
		if (!ft_strcmp(tmp1->var, lfvar))
			return (tmp2);
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	return (NULL);
}

void	env_print(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->value)
			printf("%s=%s\n", tmp->var, tmp->value);
		tmp = tmp->next;
	}
}
