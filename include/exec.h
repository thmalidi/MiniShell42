/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:36:48 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/25 08:54:01 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "env.h"

// Struct
typedef struct s_data
{
	char				*cmd;
	int					pipenb;
	int					pid;
	int					infile;
	int					outfile;
	char				**args;
	struct s_env		**env;
	struct s_data		*head;
	struct s_data		*next;
}	t_data;

typedef int	(*t_builtins)(t_data *data);

// Proto
char		*check_cmd(char **env, char *cmd);
char		**gen_args(t_data *data);
char		**is_path(char **env);
int			check_end_path(char *path);
int			check_file(char *file, int type, t_data *data);
int			element_len(t_element *list);
int			exec(t_big_list *list, t_env **env);
int			exec_hd(t_data *data, t_element *pipelist, t_big_list *list);
int			exec_nobuiltin(t_data *data);
int			is_builtin(char *cmd);
int			is_whitespace(char *cmd);
int			len_data(t_data *data);
int			manage_files(t_element **tmp, t_element **pipelist, \
						t_data *data);
int			need_to_fork(t_data *data, int builtin);
int			set_dup(t_data *list, int *fd);
int			set_pipe(t_data *list, int *fd);
t_data		*init_struct(t_big_list *list, t_env **env);
t_element	*remove_files(t_element *elt);
void		child_handler(int sig);
void		close_fd(int *fd, int n);
void		close_datafd(t_data *data);
void		exec_b(t_data *data, int builtin);
void		free_big_list(t_big_list *list);
void		free_data(t_data *data);
void		free_element(t_element **elt);
void		hd_handler(int sig);
void		ignore_signals(void);
void		init_signals(void);
void		print_data(t_data *data);

void		exit_pipe(t_data *data, int *fd, int ret);
void		exit_fork(t_data *data, char **env, int ret);

#endif