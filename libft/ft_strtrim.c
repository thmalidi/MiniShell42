/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:03:25 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/11 11:03:47 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif_l(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*cp_s1;
	int		diff;

	if (!s1 || !set)
		return (NULL);
	cp_s1 = (char *)s1;
	start = 0;
	diff = 0;
	end = ft_strlen(cp_s1) - 1;
	while ((verif_l(cp_s1[start], set) == 1) && cp_s1[start])
		start++;
	if ((size_t)start == ft_strlen(s1))
		return (ft_strdup(""));
	while ((verif_l(cp_s1[end], set) == 1) && cp_s1[end])
	{
		end--;
		diff++;
	}
	end = ft_strlen(cp_s1) - start - diff;
	return (ft_substr(cp_s1, start, end));
}
