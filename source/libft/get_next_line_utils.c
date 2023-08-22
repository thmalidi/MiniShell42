/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:05:36 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/18 12:48:37 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back_gnl(t_gnl_list **alst, t_gnl_list *new)
{
	t_gnl_list	*tmp;

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

t_gnl_list	*ft_lstnew_gnl(char *content)
{
	t_gnl_list	*elt;
	int		i;

	if (!content)
		return (NULL);
	elt = (t_gnl_list *)malloc(sizeof(t_gnl_list));
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

void	ft_lstclear_gnl(t_gnl_list **lst)
{
	t_gnl_list	*tmpb;

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

char	*return_error(t_gnl_list *list, char *buffer, int sz, int cleanbuff)
{
	if (cleanbuff == 1)
		ft_buffmove(buffer, sz);
	ft_lstclear_gnl(&list);
	return (NULL);
}
