/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:33:38 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/17 06:59:53 by hgeffroy         ###   ########.fr       */
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

void	env_clean(t_env *env)
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

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
