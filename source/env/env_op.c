/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:55:47 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/31 07:49:50 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
Retourne -2 si var est a NULL, regarder si on peut s'en servir pour la gestion du cas "export =a".
*/
int	add_to_env(t_env *env, char *var, char *value)
{
	t_env *new;
	t_env *temp;
	
	if (!var)
		return (-2); // Erreur a print pour le cas "export =a"
	new = env_newelt(var, value);
	if (!new)
		return (-1);
	if (!env)
	{
		puts("YO from addtoenv");
		env = new;
		return (0);
	}
	temp = env;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (0);
}

/*A test separement*/
/*
Retourne 0 en cas de succes, -1 si on a rien enleve.
*/
int	rm_from_env(t_env *env, char *var_to_rm)
{
	t_env	*tmp1;
	t_env	*tmp2;
	
	if (!env)
		return(-1);
	if (ft_strcmp(env->var, var_to_rm) == 0)
	{
		env = env->next; // A check, sinon return l'env.
		return (0);
	}
	tmp2 = env_lfvar(env, var_to_rm);
	if (!tmp2)
		return (-1);
	tmp1 = tmp2->next;
	tmp2->next = tmp1->next;
	env_free_elt(tmp1);
	return (-1);
}

/*
Retourne 0 en cas de succes, -1 si on a rien set.
*/
int	set_value_env(t_env *env, char *var_to_set, char *value)
{
	t_env	*new;
	t_env	*tmp1;
	t_env	*tmp2;

	
	if (!env)
		return (-1);
	tmp2 = env_lfvar(env, var_to_set);
	if (!tmp2)
		return (-1);
	tmp1 = tmp2->next;
	new = env_newelt(var_to_set, value);
	if (!new)
		return (-1);
	tmp2->next = new;
	new->next = tmp1->next;
	return (0);
	env_free_elt(tmp1);
}
