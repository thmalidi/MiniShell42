/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:13:23 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/06 08:51:42 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		printf("tab[%d] = %s\n", i, tab[i]);
}

/*
Check les eventuels arguments, je pense qu'on met juste un message d'erreur si il y a des arguments.
*/
int	env(char **env)
{
	print_tab(env);
}
