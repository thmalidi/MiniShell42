/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:17:18 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/07 19:01:00 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (dest > src)
	{	
		while (len)
		{
			((char *)dest)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	}
	else
		return (ft_memcpy(dest, src, len));
	return (dest);
}
