/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:11:01 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/08 16:11:05 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
