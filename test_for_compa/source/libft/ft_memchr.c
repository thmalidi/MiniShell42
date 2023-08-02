/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:28:58 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/08 17:29:11 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					r;
	const unsigned char	*cp_s;

	cp_s = s;
	r = 0;
	while ((size_t)r < n)
	{
		if (cp_s[r] == (unsigned char )c)
			return (((unsigned char *)s) + r);
		r++;
	}
	return (0);
}
