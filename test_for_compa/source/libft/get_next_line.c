/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:38:18 by tmalidi           #+#    #+#             */
/*   Updated: 2023/07/30 15:15:30 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*anti_leaks(char *tmp, char *buffer)
// {
// 	char	*no_leaks;

// 	no_leaks = new_ft_strjoin(tmp, buffer);
// 	free (tmp);
// 	tmp = NULL;
// 	return (no_leaks);
// }

// char	*clean_tmp(char *tmp)
// {
// 	char	*cln;
// 	int		i;

// 	i = 0;
// 	while (tmp[i] && tmp[i] != '\n')
// 		i++;
// 	if (!tmp[i])
// 		return (free(tmp), tmp = NULL, NULL);
// 	cln = malloc(sizeof(char) * ft_strlen(tmp) - i + 1);
// 	if (!cln)
// 		return (free(tmp), tmp = NULL, NULL);
// 	i++;
// 	ft_strlcpy(cln, &tmp[i], ft_strlen(tmp) - i + 1);
// 	return (free(tmp), tmp = NULL, cln);
// }

// char	*get_res(char *tmp, char *res)
// {
// 	int	i;

// 	i = 0;
// 	if (!tmp)
// 		return (NULL);
// 	while (tmp[i] && tmp[i] != '\n')
// 		i++;
// 	if (tmp[i] == '\n')
// 		i++;
// 	res = malloc(sizeof(char) * i + 1);
// 	if (!(res))
// 		return (NULL);
// 	ft_strlcpy(res, tmp, i + 1);
// 	return (res);
// }

// char	*get_brut(char *tmp, int fd)
// {
// 	char	buf[BUFFER_SIZE + 1];
// 	int		rd;

// 	if (!tmp)
// 	{
// 		tmp = malloc(sizeof(char));
// 		if (!tmp)
// 			return (NULL);
// 		tmp [0] = '\0';
// 	}
// 	rd = 1;
// 	while (rd)
// 	{
// 		rd = read(fd, buf, BUFFER_SIZE);
// 		if (rd < 0)
// 			return (NULL);
// 		buf[rd] = '\0';
// 		tmp = anti_leaks(tmp, buf);
// 		if (!tmp)
// 			return (free(tmp), tmp = NULL, NULL);
// 		if (ft_strrchr(tmp, '\n'))
// 			break ;
// 	}
// 	return (tmp);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*tmp;
// 	char		*res;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd > 1024)
// 		return (free(tmp), tmp = NULL, NULL);
// 	res = NULL;
// 	tmp = get_brut(tmp, fd);
// 	if (!tmp)
// 		return (tmp = NULL, NULL);
// 	res = get_res(tmp, res);
// 	if (!res)
// 		return (free(tmp), tmp = NULL, NULL);
// 	tmp = clean_tmp(tmp);
// 	if (res[0] == '\0')
// 		return (free(res), tmp = NULL, NULL);
// 	return (res);
// }
