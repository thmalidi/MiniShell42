/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:48:55 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/16 09:02:30 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Sort un fd avec les redirections s'il y en a.
Si plusieurs redirections du meme type dans un meme pipe => Derniere redirection prioritaire.
*/
int	check_redir(t_pipelist *pipelist, int *fd)
{
	int			err;
	t_pipelist	*temp;
	
	temp = pipelist;
	while(temp)
	{
		if (temp->elt == '<')
			err = set_infile(fd, temp->next);
		else if (temp->elt == '>')
			err = set_outfile(fd, temp->next);
		else if (temp->elt == '>>')
			err = set_outfileappend(fd, temp->next);
		else if (temp->elt == '<<')
			err = set_heredoc(); //A voir comment le gerer, ptet meme pas ds cette fonction ?
		if (err < 0)
			return (-1);
		temp = temp->next;
	}
}

/* 
Sort fd propre.
Si on impose un outfile ou un infile, on ouvre quand meme le pipe et on les met dan fd[4] pour le infile et fd[5] pour le outfile.
Si on est sur le dernier pipe, on ne doit pas ouvrir de nouveau pipe, la sortie se fera sur la sortie standard si aucun outfile n'est precise.
*/
int	set_pipe(t_pipelist *pipelist, int *fd)
{
	if (check_redir(pipelist, fd) < 0)
		return (-1);
	
}

/*
Set le dup d'entree et de sortie.
On ne doit dup que si le fd est != de .
On doit prioriser les infile et outfile aux pipes.
*/
int	set_dup(t_pipelist *pipelist, int *fd)
{
	
}

int	exec_onepipe(t_pipelist *pipelist, int *fd, char **env)
{
	set_dup(pipelist, fd);
	// Fonction de generation des arguments, on pet parcourir la liste et check le type et add si c'est une optn de commande.
	// Check si c'est un builtin d'abord !! On envoie les args dans les builtins meme s'ils ne sont pas a gere, on renverra une erreur depuis les bultins si ca ne va pas.
	// Le check de la commande se fait exactement de la meme maniere que sur pipex.
}

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
