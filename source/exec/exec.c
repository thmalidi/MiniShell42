/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:27:14 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/30 07:23:07 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pipe_manager(t_data *data, int *fd);
static int	exec_child(t_data *data, int *fd);
static int	exec_opipe(t_data *data, int *fd);
static int	wait_processes(t_data *data);

static int	exec_child(t_data *data, int *fd)
{
	int	builtin;

	rl_clear_history();
	builtin = is_builtin(data->cmd);
	signal(SIGINT, &child_handler);
	set_dup(data, fd);
	if (builtin > -1)
	{
		exec_b(data, builtin);
		free_env(*data->env);
		free_data(data->head);
		if (builtin != EXIT)
			exit (g_return_value);
		return (g_return_value);
	}
	else
		exec_nobuiltin(data);
	free_env(*data->env);
	free_data(data->head);
	return (g_return_value);
}

static int	exec_opipe(t_data *data, int *fd)
{
	int	builtin;

	if (data->cmd && is_whitespace(data->cmd) == YES)
		return (error_manager(data->cmd, CMD));
	builtin = is_builtin(data->cmd);
	if (need_to_fork(data, builtin) == 0)
		exec_b(data, builtin);
	else
	{
		data->pid = fork();
		ignore_signals();
		if (data->cmd && ft_strncmp(data->cmd, "\6", 1) == 0 && data->pid == 0)
			exit_pipe(data, fd, 0);
		if ((data->infile < 0 || data->outfile < 0) && data->pid == 0)
			exit_pipe(data, fd, 1);
		if (data->pid == 0)
			exec_child(data, fd);
	}
	return (0);
}

static int	wait_processes(t_data *data)
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

static int	pipe_manager(t_data *data, int *fd)
{
	if (!(data->cmd))
	{
		if (data->infile > 0)
			close(data->infile);
		if (data->outfile > 0)
			close(data->outfile);
	}
	if (set_pipe(data, fd) < 0)
		return (free_data(data->head), -1);
	if (exec_opipe(data, fd))
		return (free_data(data->head), -1);
	if (data->infile > 0)
		close(data->infile);
	if (data->outfile > 0)
		close(data->outfile);
	close_fd(fd, 2);
	return (0);
}

int	exec(t_big_list *list, t_env **envlst)
{
	int		fd[4];
	t_data	*data;
	t_data	*tmp;

	ft_bzero(fd, 4 * sizeof(int));
	data = init_struct(list, envlst);
	if (!data)
		return (0);
	tmp = data;
	while (tmp)
	{
		pipe_manager(tmp, fd);
		tmp = tmp->next;
	}
	wait_processes(data);
	close_fd(fd, 4);
	free_data(data);
	return (0);
}
