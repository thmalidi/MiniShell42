/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:09:43 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/11 17:22:35 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	trim_tab(char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		tmp = ft_strtrim(tab[i], " ");
		free(tab[i]);
		tab[i] = tmp;
		i++;
	}
}

t_big_list	**pars_arg(char *str, t_env **envlst)
{
	char		**tab;
	int			i;
	t_big_list	**a;
	t_big_list	*new;

	if (str[0] == '|')
		return (printf("parse error near `|'\n"), NULL);
	tab = ft_split(str, '|');
	i = 0;
	trim_tab(tab);
	a = malloc(sizeof(t_list *));
	while (tab[i])
		quote_splite(tab[i++]);
	i = 0;
	while (tab[i])
	{
		tab[i] = expand(tab[i], envlst);
		tab[i] = rp_trim(tab[i]);
		printf("<<<<<<%s\n", tab[i]);
		i++;
	}
	i = 0;
	new = ft_lstnew_big(tab[i++]);
	*a = new;
	while (tab[i])
		ft_lstadd_back_big(a, ft_lstnew_big(tab[i++]));
	return (free(tab), a);
}

int	double_quote(char *str)
{
	int	s;
	int	d;
	int	i;

	i = 0;
	s = 0;
	d = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 39) 
		{
			if (d % 2 == 0)
				s++;
		}
		if (str[i] == 34) 
		{
			if (s % 2 == 0)
				d++;
		}
		i++;
	}
	printf("simple = %d && double = %d\n",s,d);
	if (s % 2 == 0 && d % 2 == 0)
		return (1);
	return (0);
}

int	scan_cmd(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	dup = ft_strtrim(str, " ");
	while (str[i])
	{
		if ((dup[i] == 92 || dup[i] == ';') && dup[0] != 34 && dup[0] != 39)
			return (printf(
					"\033[31mError :\033[0m%c\033[31m forbidden character\033[0m\n",
					dup[i]), free(dup), 0);
		i++;
	}
	if (!double_quote(dup))
		return (printf("\033[31mError : quotes still open\033[0m\n"),
			free(dup), 0);
	return (free(dup), 1);
}

t_big_list	**parsing(char *str, t_env **envlst)
{
	t_big_list	**arg;

	if (!double_quote(str))
		return (printf("\033[31mError : quotes still open\033[0m\n"), NULL);
	arg = pars_arg(str, envlst);
	return (arg);
}
