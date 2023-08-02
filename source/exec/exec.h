/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:04:54 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/02 08:57:05 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>

// Proto
int		check_redir(t_pipelist *pipelist, t_pipe_data *data);
void	free_tab(char **tab);
void	close_all(int *fd);

// Struct
typedef struct s_pipelist {
	char 				*elt;
	int  				type;
	struct s_big_list	*pipe;
	struct s_pipelist	*next;
}  t_pipelist;

typedef struct s_big_list {
	int					lastpipe; // 1 si c'est le dernier pipe 0 sinon.
	int					heredoc;
	t_pipelist 			*pipelist;
	struct s_list		*next;
}  t_big_list;

typedef struct s_pipe_data {
	int	*fd_hd;
	int	*pid_hd;
	int	fd[6];
	int	*pid;
}	t_pipe_data;

#endif