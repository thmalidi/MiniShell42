/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:11:49 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/07 18:47:31 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cp_dst;
	const char	*cp_src;

	if (src == ((void *)0) && dst == ((void *)0))
		return (NULL);
	cp_dst = dst;
	cp_src = src;
	while (n)
	{
		*cp_dst = *cp_src;
		cp_dst++;
		cp_src++;
		n--;
	}
	return (dst);
}
