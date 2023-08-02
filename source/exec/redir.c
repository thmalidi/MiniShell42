/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:20:01 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/02 08:59:02 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*
Sort un fd avec les redirections s'il y en a.
Si plusieurs redirections du meme type dans un meme pipe => Derniere redirection prioritaire.
*/
int	check_redir(t_pipelist *pipelist, t_pipe_data *data)
{
	t_pipelist *tmp;
	int			error;

	error = 0;
	tmp = pipelist;
	while (tmp)
	{
		if (pipelist->type == 1)
			error = set_infile(data->fd, tmp->next);
		else if (pipelist->type == 2)
			error = set_heredoc(data->fd, data->fd_hd, tmp->next);
		else if (pipelist->type == 3)
			error = set_outfile(data->fd, tmp->next);
		else if (pipelist->type == 4)
			error = set_append(data->fd, tmp->next);
		tmp = tmp->next;
	}
	return (error);
}

int	set_infile(int *fd, t_pipelist *pipelist)
{
	fd[4] = open(pipelist->elt, O_RDONLY);
	if (fd[4] < 0)
	{
		perror(pipelist->elt);
		return (-1);
	}
	return (0);
}

int	set_outfile(int *fd, t_pipelist *pipelist)
{

	fd[5] = open(pipelist->elt, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd[5] < 0)
	{
		perror(pipelist->elt);
		return (-1);
	}
	return (0);
}

int	set_append(int *fd, t_pipelist *pipelist)
{
	fd[5] = open(pipelist->elt, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd[5] < 0)
	{
		perror(pipelist->elt);
		return (-1);
	}
	return (0);
}

int	set_heredoc(int *fd, int *fd_hd, t_pipelist *pipelist)
{
	fd[4] = fd_hd[(pipelist->pipe->heredoc - 1) * 2];
	return (0);
}
