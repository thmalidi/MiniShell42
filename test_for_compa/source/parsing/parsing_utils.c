/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:03:32 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/16 17:09:55 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*rp_trim(char *str)
{
	char	*tmp;

	if (str[0] == 39)
		tmp = ft_strtrim(str, "\'");
	else if (str[0] == 34)
		tmp = ft_strtrim(str, "\"");
	else
		tmp = ft_strdup(str);
	return (free(str), tmp);
}

int	pars_arg_op(char **tab, int i, t_env **envlst)
{
	trim_tab(tab);
	while (tab[i])
	{
		quote_splite(tab[i]);
		if (!scan_cmd(tab[i++]))
			return (0);
	}
	i = 0;
	while (tab[i])
	{
		tab[i] = expand(tab[i], envlst);
		tab[i] = rp_trim(tab[i]);
		i++;
	}
	return (1);
}
