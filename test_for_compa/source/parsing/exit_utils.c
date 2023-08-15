/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:48:02 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/15 09:05:56 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_te(t_element **subparsing)
{
	t_element	*tmp;
	t_element	*cu;

	tmp = *subparsing;
	while (tmp)
	{
		cu = tmp->next;
		free(tmp->str);
		free(tmp);
		tmp = cu;
	}
}

void	free_elm(t_big_list **arg)
{
	t_big_list	*tmp;

	tmp = *arg;
	while (tmp)
	{
		free_te(tmp->pipelist);
		free(tmp->pipelist);
		tmp = tmp->next;
	}
}
