/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 07:37:32 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/24 14:05:45 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newelt;
	t_list	*res;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		newelt = ft_lstnew(f(lst->content));
		if (!newelt)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, newelt);
		lst = lst->next;
	}
	return (res);
}
