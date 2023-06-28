/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:04:22 by tmalidi           #+#    #+#             */
/*   Updated: 2023/06/28 16:42:31 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//tmalidi

#ifndef MINISHELL_H
# define MINISHELL_H

//# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_history
{
	char				*content;
	struct s_history	*next;
	struct s_history	*previous;
}					t_history;

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void    free_lst(t_list **a);
char	*ft_strdup(const char *s1);
void	free_tab(char **tab);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void 	add_to_history(t_history **history, char *line);
void	plst_h(t_history **a);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_history(t_history **history);
t_list	**parsing(char *str);

#endif