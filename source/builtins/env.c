/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:13:23 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/07 12:15:19 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Check les eventuels arguments, je pense qu'on met juste un message d'erreur si il y a des arguments.
*/
int	env(char t_datalist *data, t_env *env)
{
	if (len_tab(data->args))
		printf("Env Shouldn't be ran with args");
	env_print(env);
}