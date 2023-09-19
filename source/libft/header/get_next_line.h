/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:04:25 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/19 08:57:33 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl_list
{
	char				*content;
	struct s_gnl_list	*next;
}	t_gnl_list;

int			isbreak(char *buffer);
void		ft_lstadd_back_gnl(t_gnl_list **alst, t_gnl_list *new);
void		ft_lstclear_gnl(t_gnl_list **lst);
void		ft_buffmove(char *buffer, int sz);
char		*return_error(t_gnl_list *list, char *buffer, int sz, \
							int cleanbuff);
char		*malloc_str(t_gnl_list *list, char *buffer, int sz);
char		*fill_str(t_gnl_list *list, char *buffer, int sz, char *res);
char		*get_next_line(int fd);
t_gnl_list	*ft_lstnew_gnl(char *content);

#endif
