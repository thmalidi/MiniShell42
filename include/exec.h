/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:04:54 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/11 08:49:44 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "env.h"

// Struct
typedef struct s_datalist 
{
	char				*cmd;
	int					pipenb;
	int					pid;
	int					infile;
	int					outfile;
	// int					*fd_hd; //Ceci est le pipe du dernier heredoc, fd_hd[2]
	char				**args;
	struct s_datalist	*next;
}	t_datalist;

typedef int	(*t_builtins)(t_datalist *datalist, t_env **env);

// Proto
int			element_len(t_element *list);
int			exec(t_big_list *list, t_env **env);
char		**gen_args(t_datalist *data);
t_datalist	*init_struct(t_big_list *list);
t_element	*remove_files(t_element *elt);
void		free_element(t_element *elt);
void		free_big_list(t_big_list *list);
char		*check_cmd(char **env, char *cmd);

void		print_datalist(t_datalist *datalist);
void 		print_tab(char **tab);

int			is_cmdwpath(char *cmd);
int			is_directory(char *cmd);
int			check_end_path(char *path);
char		**is_path(char **env);
int			is_whitespace(char *cmd);

int			exec_hd(t_element *pipelist);
int			isbuiltin(char *cmd);
void		close_fd(int *fd, int n);

// A del
void 	print_tab_int(int *tab, int n);

#endif