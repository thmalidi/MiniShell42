/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:03:32 by tmalidi           #+#    #+#             */
/*   Updated: 2023/10/03 11:22:06 by tmalidi          ###   ########.fr       */
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
		tab[i] = put_space(tab[i]);
		if (!tab[i])
			return (0);
		quote_splite(tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		tab[i] = expand(tab[i], envlst);
		if (!tab[i])
			return (free_tab(tab), 0);
		i++;
	}
	return (1);
}

char	*prepare_string(char *str)
{
	int	i;

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
	return (str);
}
