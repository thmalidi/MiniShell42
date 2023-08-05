/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:04:54 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/05 18:01:31 by hgeffroy         ###   ########.fr       */
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
typedef struct s_lstargs
{
	char				*arg;
	struct s_lstargs	*next;
}	t_lstargs;

typedef struct s_datalist 
{
	char				*cmd;
	int					pipenb;
	int					pid;
	int					infile;
	int					outfile;
	int					*fd_hd; //Ceci est le pipe du dernier heredoc, fd_hd[2]
	struct s_lstargs	*lstargs;
	struct s_datalist	*next;
}	t_datalist;

// Proto
int	lstargs_len(t_lstargs *list);

#endif