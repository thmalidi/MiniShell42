/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:23:51 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/22 09:48:34 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_hd(char *line, int *fd)
{
	write(fd[1], line, ft_strlen(line));
	write(fd[1], "\n", 1);
	free(line);
}

void	free_hd(char *line, t_data *data, t_big_list *list, t_env *env)
{
	free(line);
	free_datalist(data);
	free_big_list(list);
	free_env(env);
}

/*
Si on met des trucs apres le here doc, 
on doit mettre l'erreur apres la fin du heredoc.
On execute toujours le heredoc, et on met les erreurs sur le reste ensuite.
Heredoc ecrit dans le INPIPE.
elt de pipelist est le limiteur.
Il faut fork pour les signaux.
Attention c'est un process il faudra le wait !!
*/
int	exec_ohd(t_data *data, char *limiter, int *fd, t_env **env, t_big_list *list)
{
	char	*line;
	char	*line_expanded;

	ignore_signals();
	signal(SIGINT, &hd_handler);
	close(fd[0]);
	while (1)
	{
		line = readline("> ");
		if (!line && g_return_value != 130)
		{
			error_manager(limiter, HD);
			free_hd(line, data, list, *env);
			close(fd[1]);
			exit (g_return_value);
		}
		else if (g_return_value == 130)
		{
			free_hd(line, data, list, *env);
			close(fd[1]);
			exit (g_return_value);
		}
		line_expanded = expand(line, env);
		if (ft_strcmp(line_expanded, limiter) == 0)
		{
			free_hd(line_expanded, data, list, *env);
			close(fd[1]);
			exit (g_return_value);
		}
		write_hd(line_expanded, fd);
	}
}

int	exec_hd(t_data *data, t_element *elt, t_env **env, t_big_list *list)
{
	int	fd[2];
	int	pid;
	int	status;

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
		exec_ohd(data, elt->next->str, fd, env, list);
	close(fd[1]);
	waitpid(pid, &status, WUNTRACED);
	if (WIFEXITED(status))
		g_return_value = WEXITSTATUS(status);
	return (fd[0]);
}
