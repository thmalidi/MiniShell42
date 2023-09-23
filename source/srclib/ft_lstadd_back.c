/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:34:54 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/17 06:20:56 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back_big(t_big_list *lst, t_big_list *new)
{
	t_big_list	*last;

	if (lst)
	{
		if (lst == NULL)
			lst = new;
		else
		{
			last = ft_lstlast_big(lst);
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
