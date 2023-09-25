/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:17:07 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/25 08:54:11 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (*data->env)
		free_env(*data->env);
	free_data(data->head);
	rl_clear_history();
	exit (ret);
}

void	exit_fork(t_data *data, char **env, int ret)
{
	free_tab(env);
	free_data(data->head);
	rl_clear_history();
	exit (ret);
}
