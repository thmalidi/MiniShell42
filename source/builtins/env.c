/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:13:23 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/20 12:56:41 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/*
Check les eventuels arguments, je pense qu'on met juste un message d'erreur si il y a des arguments.
*/
int	env(t_pipelist *pipelist, char **env)
{
	print_tab(env);
	return (0);
}
