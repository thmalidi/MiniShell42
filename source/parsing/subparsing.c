/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:59:50 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/11 18:21:09 by tmalidi          ###   ########.fr       */
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

void	splited_arg(t_big_list **arg)
{
	char		**tab;
	t_big_list	*tmp;
	int			i;
	int			n;

	tmp = *arg;
	while (tmp)
	{
		i = 0;
		tmp->pipelist = malloc(sizeof(t_element *));
		*tmp->pipelist = NULL;
		tab = ft_split(tmp->content, ' ');
		while (tab[i])
			ft_lstadd_back_e(tmp->pipelist, ft_lstnew_e(tab[i++]));
		free_tab(tab);
		tmp = tmp->next;
	}
	tmp = *arg;
	n = 1;
	while (tmp)
	{
		subparsing(tmp->pipelist, tmp, n);
		n++;
		tmp = tmp->next;
	}
}
