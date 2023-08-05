/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:20:01 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/01 16:07:31 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*
Sort un fd avec les redirections s'il y en a.
Si plusieurs redirections du meme type dans un meme pipe => Derniere redirection prioritaire.
*/
int	check_redir(t_pipelist *pipelist, int *fd)
{
	int					err;
	const t_redirect	arr_fct[] = {&set_infile, &set_outfile, &set_append, &set_heredoc};
	t_pipelist			*temp;
	
	temp = pipelist;
	while(temp)
	{
		if (1/*temp->type == type redir*/)
		{
			if (1/*arr_fct[temp->type - type file](fd, temp->next) == -1*/)
				/*Retour d'erreur*/;
		}
		if (err < 0)
			return (-1);
		temp = temp->next;
	}
}

int	set_infile(int *fd, t_pipelist *pipelist)
{
	fd[0] = open(pipelist->elt, O_RDONLY);
	if (fd[4] < 0)
		perror(pipelist->elt);
}

int	set_outfile(int *fd, t_pipelist *pipelist)
{

	fd[5] = open(pipelist->elt, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd[5] < 0)
		perror(pipelist->elt);
}

int	set_append(int *fd, t_pipelist *pipelist)
{
	fd[5] = open(pipelist->elt, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd[5] < 0)
		perror(pipelist->elt);
}

/*
Si on met des trucs apres le here doc, on doit mettre l'erreur apres la fin du heredoc.
On execute toujours le heredoc, et on met les erreurs sur le reste ensuite.
Heredoc ecrit dans le INPIPE.
elt de pipelist est le limiteur.
Il faut fork pour les signaux.
Attention c'est un process il faudra le wait !!
*/
int	set_heredoc(int *fd_hd, t_pipelist *pipelist)
{
}