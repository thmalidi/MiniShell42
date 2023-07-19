/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:48:55 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/19 09:40:20 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* 
Sort fd propre.
Si on impose un outfile ou un infile, on ouvre quand meme le pipe et on les met dan fd[4] pour le infile et fd[5] pour le outfile.
Si on est sur le dernier pipe, on ne doit pas ouvrir de nouveau pipe, la sortie se fera sur la sortie standard si aucun outfile n'est precise.
*/
int	set_pipe(t_list *list, int *fd)
{
	if (check_redir(list->pipelist, fd) < 0)
		return (-1); //Ne pas oublier de remettre les fd[4] et fd[5] a 0 si pas de redir !! /!\ Important 
	if (pipe(&fd[2]) == -1)
		return (-1); // Msg d'erreur a mettre.
}

/*
Set le dup d'entree et de sortie.
On ne doit dup que si le fd est != de 0.
On doit prioriser les infile et outfile aux pipes.
*/
int	set_dup(t_pipelist *pipelist, int *fd)
{
	if (fd[4] > 0)
	{
		if (dup2(fd[4], STDIN_FILENO) < 0)
			return (close_all(fd), -1);
	}
	else if (fd[0] > 0)
	{
		if (dup2(fd[0], STDIN_FILENO) < 0)
			return (close_all(fd), -1);
	}
	if (fd[5] > 0)
	{
		if (dup2(fd[5], STDOUT_FILENO) < 0)
			return (close_all(fd), -1);
	}
	else if (fd[3] > 0)
	{
		if (dup2(fd[3], STDOUT_FILENO) < 0)
			return (close_all(fd), -1);
	}
	close_all(fd);
	return (0);
}

/*
Execute une fork qui correspond donc a un pipe.
Dans le cas ou l'exec ne fonctionne pas, exit avec un perror, il faudra check que le perror renvoie bien les bons trucs.
*/
int	exec_onepipe(t_pipelist *pipelist, int *fd, char **env)
{
	t_pipelist	*temp;
	char		**argstoexec;
	
	set_dup(pipelist, fd);
	argstoexec = NULL;
	while (!argstoexec && temp) // Ou alors temp->type != (type cmd) qui me parait mieux.
	{
		argstoexec = gen_args(temp);
		temp = temp->next;
	}
	// Il faut trouver la cmd a executer. Si aucune commande, on prend la premier chaine de char du pipe pour le cmd not found !!
	// Fonction de generation des arguments, on peut parcourir la liste et check le type et add si c'est une optn de commande.
	// Check si c'est un builtin d'abord !! On envoie les args dans les builtins meme s'ils ne sont pas a gere, on renverra une erreur depuis les bultins si ca ne va pas.
	// Le check de la commande se fait exactement de la meme maniere que sur pipex.
}

/*
Fonction a appeler dans le main.
*/
int	exec(t_list *list, char **env)
{
	int	i;
	int	fd[6]; //fd[4] = infile et fd[5] = outfile
	int	*pid;
	int	lstlen;

	lstlen = ft_lstlen(list);
	i = -1;
	pid = (int *)malloc(sizeof(int) * lstlen);
	if (!pid)
		return (-1);
	while (++i < lstlen)
	{
		set_pipe(fd, list); // On open le nouveau pipe, on ouvre les infile ou outfile si besoin
		pid[i] = fork();
		if (pid[i] < 0)
			return (-1); // Probablement des trucs a free la
		if(pid[i] == 0)
			exec_onepipe(list->pipelist, fd, env);
		close_inpipe(fd); // Passer le outpipe en inpipe et close l'ancien inpipe + close les eventuels outfile et infile et les enlever de fd
	}
}
