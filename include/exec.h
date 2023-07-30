/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:04:54 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/30 08:01:14 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_pipelist {
	char 				*elt;
	int  				type;
	struct s_pipelist	*next;
}  t_pipelist;

typedef struct s_list {
	int					lastpipe; // 1 si c'est le dernier pipe 0 sinon.
	t_pipelist 			*pipelist;
	struct s_list		*next;
}  t_list;

typedef	int	(*t_redirect)(int *fd, t_pipelist *pipelist);

int		check_redir(t_pipelist *pipelist, int *fd);
void	free_tab(char **tab);
void	close_all(int *fd);

#endif