/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:23:51 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/15 15:22:07 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

int	exec_ohd(char *limiter, int *fd)
{
	char	*line;

	signal(SIGINT, &hd_handler);
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			free(line);
			return (g_return_value);
		}
		if (ft_strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	exit (g_return_value);
}

int	exec_hd(t_element *pipelist)
{
	int	fd[2];
	int	pid;
	int	status;

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	ignore_signals();
	if (pid == 0)
		exec_ohd(pipelist->next->str, fd);
	close(fd[1]);
	waitpid(pid, &status, WUNTRACED);
	if (WIFEXITED(status))
		g_return_value = WEXITSTATUS(status); 
	return (fd[0]);
}
