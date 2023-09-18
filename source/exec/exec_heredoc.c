/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:23:51 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/18 13:41:33 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Si on met des trucs apres le here doc, 
on doit mettre l'erreur apres la fin du heredoc.
On execute toujours le heredoc, et on met les erreurs sur le reste ensuite.
Heredoc ecrit dans le INPIPE.
elt de pipelist est le limiteur.
Il faut fork pour les signaux.
Attention c'est un process il faudra le wait !!
*/

int	exec_ohd(char *limiter, int *fd, t_env **env)
{
	char	*line;
	char	*line_expanded;

	signal(SIGINT, &hd_handler);
	close(fd[0]);
	while (1)
	{
		line = readline("> ");
		if (!line)
			return (free(line), g_return_value);
		line_expanded = expand(line, env);
		if (!line_expanded)
			return (free(line_expanded), g_return_value);
		if (ft_strcmp(line_expanded, limiter) == 0)
		{
			free(line_expanded);
			break ;
		}
		write(fd[1], line_expanded, ft_strlen(line_expanded));
		write(fd[1], "\n", 1);
		free_env(*env);
		free(line_expanded);
	}
	exit (g_return_value);
}

int	exec_hd(t_element *pipelist, t_env **env)
{
	int	fd[2];
	int	pid;
	int	status;

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	ignore_signals();
	if (pid == 0)
		exec_ohd(pipelist->next->str, fd, env);
	close(fd[1]);
	waitpid(pid, &status, WUNTRACED);
	if (WIFEXITED(status))
		g_return_value = WEXITSTATUS(status);
	return (fd[0]);
}
