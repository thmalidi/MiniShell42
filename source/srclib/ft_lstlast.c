/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:17:11 by tmalidi           #+#    #+#             */
/*   Updated: 2023/07/14 13:30:03 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}

t_element	*ft_lstlast_e(t_element *lst)
{
	if (!lst)
		return (0);
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}
