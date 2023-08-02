/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:09:43 by tmalidi           #+#    #+#             */
/*   Updated: 2023/07/20 17:49:41 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	plst(t_list **a)
{
	t_list *tmp;

	tmp = *a;
	while(tmp)
	{
		printf("[%s]\n", tmp->content);
		tmp = tmp->next;
	}
	return;
}

t_big_list **pars_arg(char *str)
{
	char **tab;
	int i;
	t_big_list **a;
	t_big_list *new;
	
	tab = ft_split(str, '|');
	i = 0;
	a = malloc(sizeof(t_list *));
	new = ft_lstnew_big(tab[i++]);
	*a = new;
	while (tab[i])
		ft_lstadd_back_big(a, ft_lstnew_big(tab[i++]));
	free(tab);
	return a;
}

int double_quote(char *str)
{
	int i;
	int s;
	int d;

	i = 0;
	s = 0;
	d = 0;
	while (str[i])
	{
		if (str[i] == 39)
			s++;
		if (str[i] == 34)
			d++;
		i++;
	}
	if (d % 2 != 0 || s % 2 != 0)
		return 0;
	return 1;
}

int scan_cmd(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 92 || str[i] == ';')
			return (printf("\033[31mError :\033[0m%c\033[31m forbidden character\033[0m\n", str[i]),0);
		i++;
	}
	if (!double_quote(str))
		return (printf("\033[31mError : quotes still open\033[0m\n"),0);
	return 1;
}

t_big_list **parsing(char *str)
{
	t_big_list **arg;
	
	if (!scan_cmd(str))
		return (NULL);
	arg = pars_arg(str);
	return (arg);
}
