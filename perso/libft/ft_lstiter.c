/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:20:35 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/20 15:20:37 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!lst || !(*f))
		return ;
	while (lst)
	{
		tmp = lst -> next;
		(*f)(lst -> content);
		lst = tmp;
	}
}
