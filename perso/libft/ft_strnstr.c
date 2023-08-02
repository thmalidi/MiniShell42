/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:03:14 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/08 18:03:23 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*process(const char *haystack, const char *needle, size_t n)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	while (haystack[i] && (size_t)i < n)
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			while ((haystack[i + j] == needle[j]) && (size_t)(i + j) < n)
			{
				j++;
				r = i;
				if (needle[j] == '\0')
				{
					return ((char *)&haystack[r]);
				}
			}
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	if (needle[0] == '\0')
		return ((char *)&haystack[0]);
	if (n == 0)
		return (0);
	if (haystack[0] == '\0')
		return (0);
	return (process(haystack, needle, n));
}
