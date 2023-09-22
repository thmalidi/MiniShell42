/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:40:31 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/22 09:51:59 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Close les n premiers fd.
*/
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

int	element_len(t_element *list)
{
	int			len;
	t_element	*tmp;

	len = 0;
	tmp = list;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	is_builtin(char *cmd)
{
	int			i;
	const char	*builtins[] = {"cd", "echo", "env", "exit", \
							"export", "pwd", "unset", NULL};

	i = -1;
	while (builtins[++i])
	{
		if (!strcmp(cmd, builtins[i]))
			return (i);
	}
	return (-1);
}

int	len_data(t_data *data)
{
	int		len;
	t_data	*tmp;

	len = 0;
	tmp = data;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

// void	close_all(int *fd)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < 6)
// 	{
// 		if (fd[i] > 0)
// 			close (fd[i]);
// 	}
// 	return ;
// }

// void	close_inpipe(int *fd)
// {
// 	if (fd[0] > 0)
// 		close (fd[0]);
// 	if (fd[1] > 0)
// 		close (fd[1]);
// 	if (fd[4] > 0)
// 		close (fd[4]);
// 	if (fd[5] > 0)
// 		close (fd[5]);
// 	fd[4] = 0;
// 	fd[5] = 0;
// }