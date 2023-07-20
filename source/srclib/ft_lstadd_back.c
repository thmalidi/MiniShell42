/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:34:54 by tmalidi           #+#    #+#             */
/*   Updated: 2023/07/20 17:51:30 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_lstadd_back_big(t_big_list **lst, t_big_list *new)
{
	t_big_list	*last;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last = ft_lstlast_big(*lst);
			last -> next = new;
		}
	}
}

void	ft_lstadd_back_e(t_element **lst, t_element *new)
{
	t_element	*last;

	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = new;
			new->previous = NULL;
		}
		else
		{
			last = ft_lstlast_e(*lst);
			last -> next = new;
			new->previous = last;
		}
	}
}
