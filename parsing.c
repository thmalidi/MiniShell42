/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:09:43 by tmalidi           #+#    #+#             */
/*   Updated: 2023/06/26 18:03:51 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	plst(t_list **a)
{
	t_list *tmp;

	tmp = *a;
	while(tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	return;
}

t_list **pars_arg(char *str)
{
	char **tab;
	int i;
	t_list **a;
	t_list *new;
	
	tab = ft_split(str, '|');
	i = 0;
	a = malloc(sizeof(t_list *));
	new = ft_lstnew(tab[i++]);
	*a = new;
	while (tab[i])
		ft_lstadd_back(a, ft_lstnew(tab[i++]));
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
			return (printf("\033[31mError :\033[0m%c\033[31m forbidden character\033[0m", str[i]),0);
		i++;
	}
	if (!double_quote(str))
		return (printf("\033[31mError : quotes still open\033[0m"),0);
	return 1;
}

t_list **parsing(char *str)
{
	t_list **arg;
	
	if (!scan_cmd(str))
		return (NULL);
	arg = pars_arg(str);
	return (arg);
}

int main()
{
	t_list **arg;
	//t_list *tmp;
	char *line;
	int i = 0;
	
	while(i < 2)
	{
		line = readline("\033[32mMinishell>\033[0m");
		arg = parsing(line);
		//tmp = *arg;
		plst(arg);										//decommenter pour afficher les element de la liste
		free_lst(arg);
		free(line);
		i++;
	}
}