/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:03:32 by tmalidi           #+#    #+#             */
/*   Updated: 2023/09/11 15:38:02 by tmalidi          ###   ########.fr       */
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
		/*if (tab[i][1] != 34 && tab[i][1] != 39)
			tab[i] = rp_trim(tab[i]);*/
		i++;
	}
	return (1);
}

char *prepare_string(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !between(str, i) && str[i - 1] != str[i])
			str[i] = 1;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' && !between(str, i) && str[i - 1] != str[i])
			str[i] = 2;
		i++;
	}
	i = 0;
	return (str);
}