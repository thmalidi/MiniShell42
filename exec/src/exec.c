/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:48:55 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/15 11:43:01 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_dup(t_pipelist *pipelist, int *fd)
{
	
}

int	exec_onepipe(t_pipelist *pipelist, int *fd, char **env)
{
	//Check d'abord les redirections pour dup
	set_dup(pipelist, fd);
	
}

int	exec(t_list list, char **env)
{
	int	i;
	int	fd[6]; //fd[4] = infile et fd[5] = outfile
	int	*pid;

	i = -1;
	//malloc le pid
	while (++i < lstlen(list))
	{
		set_pipe(fd, list); //On open le nouveau pipe, on ouvre les infile ou oufile si besoin
		fork() //pid =
		if(//pid[i] = 0)
			exec_onepipe(list->pipelist, fd, pid, env);
		//passer le outpipe en inpipe et close l'ancien inpipe
	}
}