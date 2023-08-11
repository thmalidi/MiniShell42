/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:23:51 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/08 11:47:11 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Si on met des trucs apres le here doc, on doit mettre l'erreur apres la fin du heredoc.
On execute toujours le heredoc, et on met les erreurs sur le reste ensuite.
Heredoc ecrit dans le INPIPE.
elt de pipelist est le limiteur.
Il faut fork pour les signaux.
Attention c'est un process il faudra le wait !!
*/

/*
La question etant, est-ce qu'on supprime, la reponse etant oui
*/

int	exec_ohd(char *limiter, int *fd)
{
	char	*line;

	while (1)
	{
		line = readline(">");
		if (/*ft_*/strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		// printf("Je write %ld char !!\n", strlen(line));
		write(fd[1], line, /*ft_*/strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	return (0);
}
int	exec_hd(t_element *pipelist)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return(-1);
	exec_ohd(pipelist->next->str, fd);
	close (fd[1]);
	return (fd[0]);
}


// int main(int ac, char **av)
// {
// 	char	*limiter;
// 	char 	*line;
// 	int		fd[2];
// 	int		i;

// 	pipe(fd);
// 	i = 0;
// 	while (av[++i])
// 	{
// 		limiter = strdup(av[i]);
// 		exec_ohd(limiter, fd);
// 	}
	
// 	line = get_next_line(fd[0]);
// 	printf("%s", line);
// 	while (line)
// 	{
// 		line = get_next_line(fd[0]);
// 		printf("%s", line);
// 	}
// }
/*
gcc exec_heredoc.c -lreadline
*/