/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:27:14 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/22 09:51:59 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_child(t_data *data, int *fd, t_env **envlst)
{
	int	builtin;

	builtin = is_builtin(data->cmd);
	signal(SIGINT, &child_handler);
	set_dup(data, fd);
	if (builtin > -1)
	{
		exec_b(data, envlst, builtin);
		free_env(*envlst);
		free_data(data->head);
		if (builtin != EXIT)
			exit (g_return_value);
		return (g_return_value);
	}
	else
		exec_nobuiltin(data, envlst);
	free_data(data->head);
	free_env(*envlst);
	return (g_return_value);
}

/*
Execute une fork qui correspond donc a un pipe.
Dans le cas ou l'exec ne fonctionne pas, exit avec un perror,
il faudra check que le perror renvoie bien les bons trucs.
*/
int	exec_opipe(t_data *data, int *fd, t_env **envlst)
{
	int	builtin;

	if (ft_strcmp(data->cmd, "") == 0)
		return (error_manager("", CMD), 0);
	builtin = is_builtin(data->cmd);
	if (need_to_fork(data, builtin) == 0)
		exec_b(data, envlst, builtin);
	else
	{
		data->pid = fork();
		ignore_signals();
		if ((data->infile < 0 || data->outfile < 0) && data->pid == 0)
		{
			close_fd(fd, 4);
			close_datafd(data->head);
			free_data(data->head);
			free_env(*envlst);
			exit (1);
		}
		if (data->pid == 0)
			exec_child(data, fd, envlst);
	}
	return (0);
}

int	wait_processes(t_data *data)
{
	t_data	*tmp;
	int		status;

	tmp = data;
	status = 0;
	while (tmp)
	{
		if (tmp->pid && waitpid(tmp->pid, &status, WUNTRACED) == -1)
		{
			g_return_value = 1;
			return (-1);
		}
		else if (tmp->pid && WIFEXITED(status))
			g_return_value = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			child_handler(WTERMSIG(status));
		tmp = tmp->next;
	}
	return (0);
}

int	pipe_manager(t_data *tmp, int *fd, t_env **envlst)
{
	if (!(tmp->cmd))
	{
		if (tmp->infile)
			close(tmp->infile);
		if (tmp->outfile)
			close(tmp->outfile);
		return (-1);
	}
	if (set_pipe(tmp, fd) < 0)
		return (free_data(tmp->head), -1);
	if (exec_opipe(tmp, fd, envlst))
		return (free_data(tmp->head), -1);
	if (tmp->infile > 0)
		close(tmp->infile);
	if (tmp->outfile > 0)
		close(tmp->outfile);
	close_fd(fd, 2);
	tmp = tmp->next;
	return (0);
}

/*
Fonction a appeler dans le main.
Les heredocs sont executes dans init_struct.
Mettre les conditions sur le fork.
*/
int	exec(t_big_list *list, t_env **envlst)
{
	int		fd[4];
	t_data	*data;
	t_data	*tmp;

	ft_bzero(fd, 4 * sizeof(int));
	data = init_struct(list, envlst);
	if (!data)
	{
		return (0);
	}
	tmp = data;
	while (tmp)
	{
		pipe_manager(tmp, fd, envlst);
		tmp = tmp->next;
	}
	wait_processes(data);
	close_fd(fd, 4);
	free_data(data);
	return (0);
}

// Faire un main pour tester sans le main minishell !
