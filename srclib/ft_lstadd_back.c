/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:34:54 by tmalidi           #+#    #+#             */
/*   Updated: 2023/07/16 10:02:25 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last = ft_lstlast(*lst);
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
