/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:04:25 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/05/27 16:38:36 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

int		isbreak(char *buffer);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_buffmove(char *buffer, int sz);
char	*return_error(t_list *list, char *buffer, int sz, int cleanbuff);
char	*malloc_str(t_list *list, char *buffer, int sz);
char	*fill_str(t_list *list, char *buffer, int sz, char *res);
char	*get_next_line(int fd);
t_list	*ft_lstnew(char *content);

#endif
