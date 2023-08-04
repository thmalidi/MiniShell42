/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:04:54 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/03 14:04:19 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

// Struct
typedef struct s_pipe_data { // Qu'est ce qui est propre a tout et qu'est-ce qui est propre a chaque pipe ?
	int	*fd_hd; // Par pipe
	int	*pid_hd; // Par pipe
	int	fd[6]; // Commun a tout
	int	*pid; // Commun a tout
}	t_pipe_data;

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

// Proto
int		check_redir(t_pipelist *pipelist, t_pipe_data *data);
void	free_tab(char **tab);
void	close_all(int *fd);

#endif