/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:17:07 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/24 07:31:45 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Enleve les elts correspondants aux redirections 
apres avoir check une redirection.
*/
t_element	*remove_files(t_element *elt)
{
	t_element	*res;

	if (elt->previous)
	{
		res = elt->previous;
		if (elt->next->next)
		{
			res->next = elt->next->next;
			res->next->previous = res;
		}
		else
			res->next = NULL;
	}
	else if (elt->next->next)
	{
		res = elt->next->next;
		res->previous = NULL;
	}
	else
		res = NULL;
	free(elt->next->str);
	free(elt->next);
	free(elt->str);
	free(elt);
	return (res);
}

void	free_element(t_element **elt)
{
	t_element	*tmp1;
	t_element	*tmp2;

	if (!elt)
		return ;
	tmp2 = *elt;
	if (!tmp2)
	{
		free(elt);
		return ;
	}
	tmp1 = (*elt)->next;
	while (tmp1)
	{
		if (tmp2->str && tmp2->type)
			free(tmp2->str);
		free(tmp2);
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	if (tmp2->str && tmp2->type)
		free(tmp2->str);
	free(tmp2);
	free(elt);
}

void	free_big_list(t_big_list *list)
{
	t_big_list	*tmp1;
	t_big_list	*tmp2;

	tmp2 = list;
	if (!tmp2)
		return ;
	tmp1 = list->next;
	while (tmp1)
	{
		free(tmp2->content);
		if (tmp2->pipelist)
			free_element(tmp2->pipelist);
		free(tmp2);
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	free(tmp2->content);
	if (tmp2->pipelist)
		free_element(tmp2->pipelist);
	free(tmp2);
}

void	free_data(t_data *data)
{
	t_data	*tmp;

	if (!data)
		return ;
	close_datafd(data);
	tmp = data->next;
	while (tmp)
	{
		free(data->cmd);
		free_tab(data->args);
		free(data);
		data = tmp;
		tmp = tmp->next;
	}
	free(data->cmd);
	free_tab(data->args);
	free(data);
	return ;
}

void	exit_pipe(t_data *data, int *fd, int ret)
{
	close_fd(fd, 4);
	free_env(*data->env);
	free_data(data->head);
	rl_clear_history();
	exit (ret);
}
