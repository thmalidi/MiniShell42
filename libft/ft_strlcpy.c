/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:40:35 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/08 14:42:59 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	r;

	r = 0;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	while (src[r] && (size_t)r < dstsize - 1)
	{
		dst[r] = src[r];
		r++;
	}
	dst[r] = '\0';
	return (ft_strlen(src));
}
