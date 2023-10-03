/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:39:46 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/30 07:19:31 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_pipe(t_data *list, int *fd)
{
	close_fd(fd, 2);
	fd[0] = fd[2];
	fd[1] = fd[3];
	fd[2] = 0;
	fd[3] = 0;
	if (list->next)
	{
		if (pipe(&fd[2]) < 0)
			return (-1);
	}
	return (0);
}

int	set_dup(t_data *list, int *fd)
{
	if (list->infile > 0)
		dup2(list->infile, STDIN_FILENO);
	else if (fd[0] > 0)
		dup2(fd[0], STDIN_FILENO);
	if (list->outfile > 0)
		dup2(list->outfile, STDOUT_FILENO);
	else if (fd[3] > 0)
		dup2(fd[3], STDOUT_FILENO);
	close_fd(fd, 4);
	close_datafd(list->head);
	return (0);
}

void	exec_b(t_data *data, int builtin)
{
	const t_builtins	tab_builtins[] = {&cd_b, &echo_b, &env_b, \
										&exit_b, &export_b, &pwd_b, &unset_b};

	(*tab_builtins[builtin])(data);
}

int	exec_nobuiltin(t_data *data)
{
	char	*cmdwpath;
	char	**env;

	signal(SIGQUIT, &child_handler);
	g_return_value = 0;
	env = env_to_tab(*data->env);
	free_env(*data->env);
	if (!env)
	{
		error_manager(data->cmd, NOPATH);
		free_tab(env);
		free_data(data->head);
		exit (g_return_value);
	}
	cmdwpath = check_cmd(env, data->cmd);
	if (!cmdwpath)
	{
		free_tab(env);
		free_data(data->head);
		exit (g_return_value);
	}
	else
		execve(cmdwpath, data->args, env);
	return (free(cmdwpath), free_tab(env), free_data(data->head), \
			g_return_value);
}

int	need_to_fork(t_data *data, int builtin)
{
	if (builtin < 0)
	{
		return (1);
	}
	if (len_data(data->head) == 1)
	{
		if ((builtin == EXPORT && !(data->args)[1]) || builtin == ECHO \
			|| builtin == PWD || builtin == ENV)
			return (1);
		else
			return (0);
	}
	else
	{
		return (1);
	}
}
