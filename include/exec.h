/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:36:48 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/23 08:05:13 by hgeffroy         ###   ########.fr       */
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
int			element_len(t_element *list);
int			exec(t_big_list *list, t_env **env);
int			exec_hd(t_data *data, t_element *pipelist, t_big_list *list);
int			is_builtin(char *cmd);
int			is_whitespace(char *cmd);
t_data		*init_struct(t_big_list *list, t_env **env);
t_element	*remove_files(t_element *elt);
void		close_fd(int *fd, int n);
void		free_big_list(t_big_list *list);
void		free_data(t_data *data);
void		free_element(t_element **elt);
void		print_data(t_data *data);

void		init_signals(void);
void		ignore_signals(void);
void		child_handler(int sig);
int			len_data(t_data *data);
void		hd_handler(int sig);
int			check_file(char *file, int type, t_data *data);
int			manage_files(t_element **tmp, t_element **pipelist, \
						t_data *data);

int			set_pipe(t_data *list, int *fd);
int			set_dup(t_data *list, int *fd);
void		exec_b(t_data *data, int builtin);
int			exec_nobuiltin(t_data *data);
int			need_to_fork(t_data *data, int builtin);
void		close_datafd(t_data *data);

#endif