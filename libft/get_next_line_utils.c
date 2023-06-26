/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:38:40 by tmalidi           #+#    #+#             */
/*   Updated: 2023/02/07 14:25:18 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlcpy_new(char *dst, const char *src, size_t dstsize)
{
	int	r;

	r = 0;
	if (dstsize == 0)
	{
		return ;
	}
	while (src[r] && (size_t)r < dstsize - 1)
	{
		dst[r] = src[r];
		r++;
	}
	dst[r] = '\0';
}

char	*new_ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		l_sts;
	int		l_b;

	l_sts = ft_strlen(s1);
	l_b = ft_strlen(s2);
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * l_sts + l_b + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, l_sts + 1);
	ft_strlcpy(str + l_sts, s2, l_b + 1);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strrchr(const char *s, int c)
{
	int	r;

	r = ft_strlen(s);
	while (r >= 0)
	{
		if (s[r] == (char)c)
			return ((char *)s + r);
		r--;
	}
	return (NULL);
}