/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:39:57 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/20 14:51:14 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !(*del))
		return ;
	while (*lst)
	{
		tmp = (*lst)-> next;
		(*del)((*lst)-> content);
		free(*lst);
		(*lst) = tmp;
	}
}
