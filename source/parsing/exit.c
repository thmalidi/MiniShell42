/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:58:26 by tmalidi           #+#    #+#             */
/*   Updated: 2023/09/29 08:23:19 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_history_content(t_history *history)
{
	t_history	*temp;

	while (history != NULL)
	{
		temp = history;
		history = history->next;
		free(temp->content);
		free(temp);
	}
	free(history);
}

void	free_history(t_history **history)
{
	free_history_content(*history);
	free(history);
}

void	free_lst_content(t_big_list *a)
{
	t_big_list	*temp;

	while (a != NULL)
	{
		temp = a;
		a = temp->next;
		free(temp->content);
		free(temp);
	}
}

void	free_lst(t_big_list *a)
{
	free_lst_content(a);
}
