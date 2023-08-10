/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:11:11 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/08 13:38:25 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	trim_tab(char **tab)
{
	int i;
	char *tmp;
	
	i = 0;
	while (tab[i])
	{
		tmp = ft_strtrim(tab[i], " ");
		free(tab[i]);
		tab[i] = tmp;
		i++;
	}
}

void    manage_tab(char **tab)
{
    int i;
    
	i = 0;
	trim_tab(tab);
	while (tab[i])
		quote_splite(tab[i++]);
	i = 0;
	while(tab[i])
	{
		tab[i] = expand(tab[i]);
		i++;
	}
}*/