/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:59:50 by tmalidi           #+#    #+#             */
/*   Updated: 2023/10/01 15:34:55 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_element	*ft_lstnew_e(char *str)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!new)
		return (0);
	new->str = ft_strdup(str);
	new->type = -2;
	new->next = NULL;
	return (new);
}

void	space_process(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		tab[i] = put_space(tab[i]);
		i++;
	}
}

void	fill_pipelist(t_big_list *tmp)
{
	int	n;

	n = 1;
	while (tmp && tmp->content)
	{
		subparsing(tmp->pipelist, tmp, n++);
		tmp = tmp->next;
	}
}

int	splited_arg(t_big_list *arg)
{
	char		**tab;
	t_big_list	*tmp;
	int			i;

	tmp = arg;
	while (tmp && tmp->content)
	{
		tmp->pipelist = malloc(sizeof(t_element *));
		if (!tmp->pipelist)
			return (free_big_list(arg)
				, error_manager("splited_arg", MALLOC), 0);
		*tmp->pipelist = NULL;
		tmp->content = put_space(tmp->content);
		tab = ft_split(tmp->content, ' ');
		if (!tab)
			return (free_big_list(arg)
				, error_manager("splited_arg(ft_split)", MALLOC), 0);
		i = 0;
		while (tab[i])
			ft_lstadd_back_e(tmp->pipelist, ft_lstnew_e(tab[i++]));
		free_tab(tab);
		tmp = tmp->next;
	}
	tmp = arg;
	return (fill_pipelist(tmp), 1);
}
