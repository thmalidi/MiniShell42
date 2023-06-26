/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:56:25 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/08 15:56:29 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	r;

	r = 0;
	while ((size_t)r <= ft_strlen(s))
	{
		if (s[r] == (char) c)
			return (((char *)s) + r);
		r++;
	}
	return (0);
}
