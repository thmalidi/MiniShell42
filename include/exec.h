/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:04:54 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/18 15:50:12 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	char				**args;
	struct s_datalist	*next;
}	t_datalist;

typedef int	(*t_builtins)(t_datalist *datalist, t_env **env);

// Proto
char		*check_cmd(char **env, char *cmd);
char		**gen_args(t_datalist *data);
char		**is_path(char **env);
int			check_end_path(char *path);
int			element_len(t_element *list);
int			exec(t_big_list *list, t_env **env);
int			exec_hd(t_element *pipelist, t_env **env);
int			is_builtin(char *cmd);
int			is_whitespace(char *cmd);
t_datalist	*init_struct(t_big_list *list, t_env **env);
t_element	*remove_files(t_element *elt);
void		close_fd(int *fd, int n);
void		free_big_list(t_big_list *list);
void		free_datalist(t_datalist *datalist);
void		free_element(t_element **elt);
void		print_datalist(t_datalist *datalist);

void		init_signals(void);
void		ignore_signals(void);
void		child_handler(int sig);
int			len_datalist(t_datalist *datalist);
void		hd_handler(int sig);
int			check_file(char *file, int type, t_datalist *datalist);
int			manage_files(t_element **tmp, t_element **pipelist, t_datalist *datalist);

int			set_pipe(t_datalist *list, int *fd);
int			set_dup(t_datalist *list, int *fd);
void		exec_builtin(t_datalist *datalist, t_env **envlst, int builtin);
int			exec_nobuiltin(t_datalist *data, t_env **envlst, t_datalist *full_data);
int			need_to_fork(t_datalist *datalist, int builtin);

#endif