/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:48:55 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/01 16:09:08 by hgeffroy         ###   ########.fr       */
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
	if (list->next)
		return (0);
	if (pipe(&fd[2]) == -1)
		return (-1); // Msg d'erreur a mettre.
	return (0);
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
Exec une commande qui n'est pas un builtin.
*/
int	exec_cmd(t_pipelist *pipelist, int *fd, char **env)
{
	char **argstoexec;

	argstoexec = gen_args(pipelist);
	if (!argstoexec)
		return (-1);
	execve(argstoexec[0], argstoexec, env);
	free_tab(argstoexec);
	exit(1);
}

/*
Exec une commande qui est un builtin.
*/
int	exec_builtin(t_pipelist *pipelist, int *fd)
{
	// Faire un ptr sur fct
}

/*
Execute une fork qui correspond donc a un pipe.
Dans le cas ou l'exec ne fonctionne pas, exit avec un perror, il faudra check que le perror renvoie bien les bons trucs.
*/
int	exec_onepipe(t_pipelist *pipelist, int *fd, char **env)
{
	t_pipelist	*temp;
	
	set_dup(pipelist, fd);
	while (temp /*&& temp->type != commande && temp-> type != builtin */)
		temp = temp->next;
	if (1 /*temp->type = cmd*/)
		exec_cmd(temp, fd, env);
	else if (1 /*temp->type = builtin*/)
		exec_builtin(temp, fd); // Ajouter l'env ?
	else
		/* Il n'y a pas de cmd dans le pipe, faire en fonction */; //Cmd not found sur le premier argument.
}

/*
Fonction a appeler dans le main.
Il faut d'abord faire un tour sur les heredoc et ENSUITE faire les autres.
Il faudra donc stocker les heredoc du premier passage.
*/
int	exec(t_list *list, t_env *env)
{
	
}

// Faire un main pour tester !!!