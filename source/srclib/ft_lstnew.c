/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:04:43 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/17 06:47:20 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_big_list	*ft_lstnew_big(void *content)
{
	t_big_list	*new;

	new = malloc(sizeof(t_big_list) * 1);
	if (!new)
		return (0);
	new -> content = content;
	new -> next = NULL;
	return (new);
}
