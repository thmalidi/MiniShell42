/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:00:17 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/07 17:02:05 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		r;
	char	*str;

	str = b;
	r = 0;
	while ((size_t)r < len)
	{
		str[r] = (unsigned char)c;
		r++;
	}
	return (b);
}
