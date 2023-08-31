/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:55:47 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/30 14:29:14 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Retourne -2 si var est a NULL, 
regarder si on peut s'en servir pour la gestion du cas "export =a".
*/
int	add_to_env(t_env **env, char *var, char *value)
{
	t_env	*new;
	t_env	*temp;

	if (!var)
		return (-2); // Erreur a print pour le cas "export =a"
	new = env_newelt(var, value);
	if (!new)
		return (-1);
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

/*A test separement*/
/*
Retourne 0 en cas de succes, -1 sinon. Ne rien enlever est un succes !
*/
int	rm_from_env(t_env **env, char *var_to_rm)
{
	t_env	*tmp1;
	t_env	*tmp2;

	if (!env || !(*env))
		return (-1);
	if (ft_strcmp((*env)->var, var_to_rm) == 0)
	{
		*env = (*env)->next; // A check, sinon return l'env.
		return (0);
	}
	tmp2 = env_lfvar(*env, var_to_rm);
	if (!tmp2)
		return (0);
	tmp1 = tmp2->next;
	// printf("tmp2 var = %s\n", tmp2->var);
	// printf("tmp1 var = %s\n", tmp1->var);
	tmp2->next = tmp1->next;
	env_free_elt(tmp1);
	return (0);
}

/*
Retourne 0 en cas de succes, -1 si on a rien set.
*/
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
	}
	else
	{
		tmp1 = tmp1->next;
		free(tmp1->value);
		tmp1->value = ft_strdup(value);
	}
	return (0);
}

/*
Retourne la valeur de la variable d'environnement var.
Retourne NULL s'il ne trouve pas var.
Attention, elle n'est pas malloc (C'est completement faisable si besoin)!
*/
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
