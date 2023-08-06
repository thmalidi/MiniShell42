/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:04:54 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/06 16:35:50 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

// Struct
typedef struct s_datalist 
{
	char				*cmd;
	int					pipenb;
	int					pid;
	int					infile;
	int					outfile;
	int					*fd_hd; //Ceci est le pipe du dernier heredoc, fd_hd[2]
	char				**args;
	struct s_datalist	*next;
}	t_datalist;

// Proto
int			element_len(t_element *list);
int			exec(t_big_list *list, char **env);
char		**gen_args(t_datalist *data);
t_datalist	*init_struct(t_big_list *list);
t_element	*remove_files(t_element *elt);
void		free_element(t_element *elt);
void		free_big_list(t_big_list *list);

void		print_datalist(t_datalist *datalist);
void 		print_tab(char **tab);

#endif