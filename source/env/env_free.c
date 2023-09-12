/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:33:38 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/12 10:58:45 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
