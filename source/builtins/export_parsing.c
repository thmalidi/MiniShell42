/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:11:09 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/30 07:45:10 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	fill_tab(char **tab, char *arg, int index_split, int n);
static char	**ft_split_export(char *arg);

static int	fill_tab(char **tab, char *arg, int index_split, int n)
{
	int	i;

	tab[0] = (char *)malloc(sizeof(char) * (index_split + 2));
	if (!tab[0])
		return (error_manager("fill_tab", MALLOC), -1);
	if (n > 1)
	{
		tab[1] = (char *)malloc(sizeof(char) * (ft_strlen(arg) - index_split));
		if (!tab[1])
			return (error_manager("fill_tab", MALLOC), -1);
	}
	tab[n] = NULL;
	i = -1;
	while (++i < index_split)
		tab[0][i] = arg[i];
	tab[0][i] = '\0';
	while (++i < (int)ft_strlen(arg) && n > 1)
		tab[1][i - index_split - 1] = arg[i];
	if (n > 1)
		tab[1][i - index_split - 1] = '\0';
	return (0);
}

static char	**ft_split_export(char *arg)
{
	int		i;
	int		n;
	char	**res;

	i = -1;
	while (arg[++i] && arg[i] != '=')
		;
	if (i < (int)ft_strlen(arg) \
		|| (arg[i] == '=' && arg[i] == (int)ft_strlen(arg)))
		n = 2;
	else
		n = 1;
	res = (char **)malloc(sizeof(char *) * (n + 1));
	if (!res)
		return (error_manager("ft_split_export", MALLOC), NULL);
	if (fill_tab(res, arg, i, n) < 0)
		return (free_tab(res), NULL);
	res[n] = NULL;
	return (res);
}

char	**parsing_export(char *arg)
{
	char	**res;

	res = ft_split_export(arg);
	if (!res)
		return (NULL);
	if (check_var(res[0], "export") < 0)
		return (free_tab(res), NULL);
	return (res);
}
