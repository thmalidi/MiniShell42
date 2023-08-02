/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:18:42 by tmalidi           #+#    #+#             */
/*   Updated: 2023/06/28 16:36:24 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	plst_h(t_history **a)
{
	t_history *tmp;
	int i;

	i = 1;
	tmp = *a;
	while(tmp)
	{
		if (i != 0)
		{
			printf("%d %s\n", i++, tmp->content);
			tmp = tmp->next;
		}
	}
	return;
}

t_history	*ft_lstlast_h(t_history *lst)
{
	if (!lst)
		return (0);
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}

void	ft_lst_history(t_history **history, t_history *new)
{
	t_history	*last;

	if (history)
	{
		if (*history == NULL)
		{
			*history = new;
			new->previous = NULL;
		}
		else
		{
			last = ft_lstlast_h(*history);
			last -> next = new;
			new -> previous = last;
		}
	}
}

t_history	*ft_lstnew_h(void *content)
{
	t_history	*new;

	new = malloc(sizeof(t_history) * 1);
	if (!new)
		return (0);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

void add_to_history(t_history **history, char *line)
{
	t_history *new;
	
	new = ft_lstnew_h(line);
	if (!history)
	{
		history = malloc(sizeof(t_list *));
		*history = new;
	}
	else
		ft_lst_history(history, new);
}