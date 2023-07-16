/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:20:01 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/16 17:18:23 by hgeffroy         ###   ########.fr       */
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
		if (temp->type == ?) //Definir le type avec Theo
		{
			if (arr_fct[temp->type - ? /*type infile*/](fd, temp->next) == -1)
				/*Retour d'erreur*/
		}
		if (err < 0)
			return (-1);
		temp = temp->next;
	}
}

int	set_infile(int *fd, t_pipelist *file)
{
	
}

int	set_outfile(int *fd, t_pipelist *file)
{
	
}

int	set_append(int *fd, t_pipelist *file)
{
	
}

int	set_heredoc(int *fd, t_pipelist *file)
{
	
}