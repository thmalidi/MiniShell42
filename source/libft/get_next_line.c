/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:05:33 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/19 08:58:28 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	isbreak(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i] != 0)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_buffmove(char *buffer, int sz)
{
	int	i;
	int	len;

	if (!buffer)
		return ;
	len = 0;
	if (sz == 0 || (sz < BUFFER_SIZE && isbreak(buffer) == -1)
		|| isbreak(buffer) + 1 == sz)
	{
		buffer[0] = 0;
		return ;
	}
	while (buffer[len] && buffer[len] != '\n' && len < sz + 1)
		len++;
	i = -1;
	while (++i < sz - len - 1 && buffer[len + i + 1] != 0)
		buffer[i] = buffer[len + i + 1];
	while (i < BUFFER_SIZE && buffer[i] != 0)
		buffer[i++] = 0;
}

char	*malloc_str(t_gnl_list *list, char *buffer, int sz)
{
	int		lstlen;
	int		strlen;
	int		i;
	char	*res;

	lstlen = 0;
	while (list)
	{
		i = -1;
		while ((list->content)[++i] && i < BUFFER_SIZE)
			lstlen++;
		list = list->next;
	}
	strlen = lstlen;
	while (buffer[strlen - lstlen] != '\n'
		&& strlen - lstlen < sz && buffer[strlen - lstlen])
		strlen++;
	if (buffer[strlen - lstlen] == '\n')
		strlen++;
	res = (char *)malloc(strlen + 1);
	if (!res)
		return (NULL);
	return (res);
}

char	*fill_str(t_gnl_list *list, char *buffer, int sz, char *res)
{
	int		i;
	int		j;

	i = 0;
	while (list)
	{
		j = 0;
		while (j < BUFFER_SIZE && (list->content)[j] \
				&& (list->content)[j] != '\n')
			res[i++] = (list->content)[j++];
		list = list->next;
	}
	j = 0;
	while (buffer[j] != '\n' && buffer[j] && j < sz)
		res[i++] = buffer[j++];
	if (isbreak(buffer) != -1)
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static int		sz;
	t_gnl_list		*list;
	static char		buffer[BUFFER_SIZE];
	char			*res;

	list = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (buffer[0] == 0)
		sz = read(fd, buffer, BUFFER_SIZE);
	if (sz <= 0)
		return (return_error(list, buffer, sz, 0));
	while (isbreak(buffer) == -1 && !((sz < BUFFER_SIZE) || sz < 0))
	{
		ft_lstadd_back_gnl(&list, ft_lstnew_gnl(buffer));
		sz = read(fd, buffer, BUFFER_SIZE);
		if (sz < 0)
			return (return_error(list, buffer, sz, 1));
	}
	res = malloc_str(list, buffer, sz);
	if (!res)
		return (return_error(list, buffer, sz, 0));
	res = fill_str(list, buffer, sz, res);
	return (ft_buffmove(buffer, sz), ft_lstclear_gnl(&list), res);
}
