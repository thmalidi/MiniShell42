/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:43:41 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/08 14:50:15 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	r;
	int	l;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	if (ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	r = ft_strlen(dst);
	l = 0;
	while ((size_t)r < dstsize - 1 && src[l])
	{
		dst[r] = src[l];
		r++;
		l++;
	}
	dst[r] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[l]));
}
