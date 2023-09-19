/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:23:51 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/19 11:15:10 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_hd(char *line, int *fd)
{
	write(fd[1], line, ft_strlen(line));
	write(fd[1], "\n", 1);
	free(line);
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
		{
			free(line);
			close(fd[1]);
			exit (g_return_value);
		}
		line_expanded = expand(line, env); // Changer expand pour retourner \0 si seulement \n ?
		// if (!line_expanded)
		// 	return (free(line_expanded), g_return_value);
		free_env(*env);
		if (ft_strcmp(line_expanded, limiter) == 0)
		{
			free(line_expanded);
			close(fd[1]);
			exit (g_return_value);
		}
		write_hd(line_expanded, fd);
	}
}

int	exec_hd(t_element *pipelist, t_env **env, t_big_list *list)
{
	int	fd[2];
	int	pid;
	int	status;

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	ignore_signals();
	if (pid == 0)
	{
		free_big_list(list);
		exec_ohd(pipelist->next->str, fd, env);
	}
	close(fd[1]);
	waitpid(pid, &status, WUNTRACED);
	if (WIFEXITED(status))
		g_return_value = WEXITSTATUS(status);
	return (fd[0]);
}
