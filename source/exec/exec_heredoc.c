/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:23:51 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/30 07:06:02 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_ohd(t_data *data, char *limiter, int *fd, t_big_list *list);
static void	free_hd(char *line, t_data *data, t_big_list *list, int *fd);
static void	write_hd(char *line, int *fd);

static void	write_hd(char *line, int *fd)
{
	write(fd[1], line, ft_strlen(line));
	write(fd[1], "\n", 1);
	free(line);
}

static void	free_hd(char *line, t_data *data, t_big_list *list, int *fd)
{
	free(line);
	free_env(*(data->env));
	free_data(data);
	free_big_list(list);
	close_fd(fd, 2);
	rl_clear_history();
	exit (g_return_value);
}

static int	exec_ohd(t_data *data, char *limiter, int *fd, t_big_list *list)
{
	char	*line;
	char	*line_expanded;

	signal(SIGINT, &hd_handler);
	g_return_value = 0;
	while (1)
	{
		line = readline("> ");
		if (!line && g_return_value != 130)
		{
			error_manager(limiter, HD);
			free_hd(line, data, list, fd);
		}
		else if (g_return_value == 130)
			free_hd(line, data, list, fd);
		if (ft_strcmp(line, limiter) == 0)
			free_hd(line, data, list, fd);
		if (line)
			line_expanded = expand(line, data->env);
		write_hd(line_expanded, fd);
	}
}

int	exec_hd(t_data *data, t_element *elt, t_big_list *list)
{
	int	fd[2];
	int	pid;
	int	status;

	ignore_signals();
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
		exec_ohd(data, elt->next->str, fd, list);
	close(fd[1]);
	waitpid(pid, &status, WUNTRACED);
	if (WIFEXITED(status))
	{
		g_return_value = WEXITSTATUS(status);
		if (g_return_value == 130)
			return (close(fd[0]), 0);
	}
	return (fd[0]);
}
