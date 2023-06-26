/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:04:22 by tmalidi           #+#    #+#             */
/*   Updated: 2023/06/26 17:33:59 by tmalidi          ###   ########.fr       */
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

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void    free_lst(t_list **a);
char	*ft_strdup(const char *s1);
void	free_tab(char **tab);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);

#endif