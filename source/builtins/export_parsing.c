/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:02:34 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/30 10:54:32 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Retourne -1 si ce n'est pas une var qu'on peut mettre dans l'env, 0 sinon.
*/
int	check_var(char *var)
{
	int	i;

	if (!var)
		return (-1);
	if (!ft_isalpha(var[0]) && var[0] != '_')
		return (-1);
	i = 0;
	while (var[++i])
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (-1);
	}
	return (0);
}

int		fill_tab(char **tab, char *arg, int index_split, int n)
{
	int	i;
	
	tab[0] = (char *)malloc(sizeof(char) * (index_split + 2)); // Proteger !!
	if (!tab[0])
		return (-1);
	if (n > 1)
		tab[1] = (char *)malloc(sizeof(char) * (ft_strlen(arg) - index_split)); // Proteger !!
	tab[n] = NULL;
	i = -1;
	while (++i < index_split)
		tab[0][i] = arg[i];
	tab[0][i] = '\0';
	while (++i < (int)ft_strlen(arg) && n > 1)
		tab[1][i - index_split - 1] = arg[i];
	tab[1][i - index_split - 1] = '\0';
	return (0);
}

char	**ft_split_export(char *arg)
{
	int		i;
	int		n;
	char	**res;

	i = -1;
	while (arg[++i] && arg[i] != '=')
		;
	if (i < (int)ft_strlen(arg) || (arg[i] == '=' && arg[i] == (int)ft_strlen(arg)))
		n = 2;
	else
		n = 1;
	res = (char **)malloc(sizeof(char *) * (n + 1));
	if (fill_tab(res, arg, i, n) < 0)
		return (free_tab(res), NULL);
	return (res);
}

char	**parsing_export(char *arg)
{
	char	**res;

	res = ft_split_export(arg);
	if (check_var(res[0]) < 0)
		return (free_tab(res), NULL);
	return (res);
}
