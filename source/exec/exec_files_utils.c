/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_files_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:49:14 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/29 08:22:17 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fd(int *fd, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (fd[i] > 0)
			close (fd[i]);
		i++;
	}
}

void	close_datafd(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	while (tmp)
	{
		if (tmp->infile > 0)
			close(tmp->infile);
		if (tmp->outfile > 0)
			close(tmp->outfile);
		tmp = tmp->next;
	}
}

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
