/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:09:43 by tmalidi           #+#    #+#             */
/*   Updated: 2023/10/02 15:50:37 by tmalidi          ###   ########.fr       */
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
		if (!tmp)
			error_manager("trim_tab(ft_strtrim)", MALLOC);
		free(tab[i]);
		tab[i] = tmp;
		i++;
	}
}

t_big_list	*make_lst(char **tab, t_big_list *new, int i)
{
	t_big_list	*a;
	t_big_list	*c;
	int			len;

	a = new;
	len = len_tab(tab);
	while (tab[i])
	{
		if (tab[i])
		{
			c = ft_lstnew_big(tab[i++]);
			if (!c)
				return (free(a), free_r(tab, len), NULL);
			ft_lstadd_back_big(a, c);
		}
	}
	return (a);
}

t_big_list	*pars_arg(char *str, t_env **envlst)
{
	char		**tab;
	int			i;
	t_big_list	*new;

	if (str[0] == '|' || str[ft_strlen(str) - 1] == '|')
		return (error_manager("|", SYNTAX), NULL);
	tab = ft_split(str, '|');
	if (!tab)
		return (error_manager("pars_arg(ft_split)", MALLOC), NULL);
	i = 0;
	if (!pars_arg_op(tab, i, envlst))
		return (free_tab(tab), NULL);
	i = 0;
	if (!tab[i])
		i++;
	new = ft_lstnew_big(tab[i]);
	if (!new)
		return (free_tab(tab)
			, error_manager("pars_arg(ft_lstnew_big)", MALLOC), NULL);
	if (tab[i])
		i++;
	else
		return (free(new), free(tab), NULL);
	new = make_lst(tab, new, i);
	return (free(tab), new);
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
	if (s % 2 == 0 && d % 2 == 0)
		return (1);
	return (0);
}

t_big_list	*parsing(char *str, t_env **envlst)
{
	t_big_list	*arg;
	int			i;

	i = 0;
	arg = NULL;
	while (str[i])
	{
		if (str[i] == '|' && str[i + 1] && str[i + 1] == '|'
			&& between(str, i + 1) && str[i + 2]
			&& str[i + 2] == '|' && between(str, i + 2))
			return (error_manager("|", SYNTAX), NULL);
		if (str[i] == '|' && !between(str, i))
			str[i] = 3;
		if (str[i] == '<' && !between(str, i))
			str[i] = 4;
		if (str[i] == '>' && !between(str, i))
			str[i] = 5;
		if (str[i] == '$' && (!interpreted(str, i) || (!between(str, i)
					&& !ft_isalnum(str[i + 1]) && str[i + 1] != '?')))
			str[i] = -1;
		i++;
	}
	return (end_check(str, arg, envlst));
}
