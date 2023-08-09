/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:30:29 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/09 14:40:07 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_tab(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);	
}

/*
Retourne -1 si ce n'est pas une var qu'on peut mettre dans l'env, 0 sinon.
*/
int	check_var(char *var)
{
	int	i;

	if (!var)
		return (-1);
	if (!ft_isalpha(var[0]) && var[0] != '_') /*var[0] est autre chose qu'une lettre ou _*/
		return (-1);
	i = 0;
	while (++i)
	{
		if (!ft_isalnum(var[i]) && var[i] != '_') /*var[i] est autre chose qu'un alphanum ou _*/
			return (-1);
	}
	return (0);
}
