/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:04:22 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/11 17:09:28 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//tmalidi

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../source/libft/libft.h"
# include "builtins.h"
# include "env.h"
// # include "exec.h"

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>

typedef struct s_element
{
	int					type;
	char				*str;
	struct s_element 	*previous;
	struct s_element 	*next;
}			t_element;

typedef struct s_big_list
{
	int					here_doc;
	int					builtin;
	int					cmd;
	char				**env;
	char				*content;
	t_element			**pipelist;
	struct s_big_list	*next;
}					t_big_list;

typedef struct s_history
{
	char				*content;
	struct s_history	*next;
	struct s_history	*previous;
}						t_history;

void	free_lst(t_big_list **a);
void	free_tab(char **tab);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back_e(t_element **lst, t_element *new);
t_list	*ft_lstlast(t_list *lst);
t_element	*ft_lstlast_e(t_element *lst);
void 	add_to_history(t_history **history, char *line);
void	plst_h(t_history **a);
void	free_history(t_history **history);
t_big_list **parsing(char *str, t_env **envlst);
void	plst(t_big_list **a);
void    splited_arg(t_big_list **arg);
void    free_elm(t_big_list **arg);
int		subparsing(t_element **subparsing, t_big_list *arg, int n);
void	printf_tab(char **tab);

void	ft_lstadd_back_big(t_big_list **lst, t_big_list *new);
t_big_list	*ft_lstnew_big(void *content);
t_big_list	*ft_lstlast_big(t_big_list *lst);

void clean_str(char *str);
void quote_splite(char *str);
char	*expand_process(char *str, t_env *envlst);
char	*expand(char *str, t_env **env);
void    manage_tab(char **tab);
int		scan_cmd(char *str);
int		is_ok(t_big_list **a);
int		double_quote(char *str);

char *rp_trim(char *str);

#endif