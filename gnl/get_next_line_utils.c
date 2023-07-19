/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:05:36 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/05/26 10:43:21 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!new || !alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*ft_lstnew(char *content)
{
	t_list	*elt;
	int		i;

	if (!content)
		return (NULL);
	elt = (t_list *)malloc(sizeof(t_list));
	if (!elt)
		return (NULL);
	elt->content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(elt->content))
	{
		free(elt);
		return (NULL);
	}
	i = -1;
	while (++i < BUFFER_SIZE)
		(elt->content)[i] = content[i];
	while (i < BUFFER_SIZE)
		(elt->content)[i++] = 0;
	elt->next = NULL;
	return (elt);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmpb;

	if (!lst)
		return ;
	if (!*lst)
	{
		lst = NULL;
		return ;
	}
	while (*lst)
	{
		tmpb = *lst;
		*lst = (*lst)->next;
		free((tmpb)->content);
		free(tmpb);
	}
	*lst = NULL;
}

char	*return_error(t_list *list, char *buffer, int sz, int cleanbuff)
{
	if (cleanbuff == 1)
		ft_buffmove(buffer, sz);
	ft_lstclear(&list);
	return (NULL);
}
