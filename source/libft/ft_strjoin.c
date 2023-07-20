/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:43:20 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/11 09:43:24 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpy(char *str, char *cp_s1, char *cp_s2)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	while (cp_s1[i])
	{
		str[r] = cp_s1[i];
		i++;
		r++;
	}
	i = 0;
	while (cp_s2[i])
	{
		str[r] = cp_s2[i];
		i++;
		r++;
	}
	str[r] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*cp_s1;
	char	*cp_s2;

	if (!s1 || !s2)
		return (0);
	cp_s1 = (char *)s1;
	cp_s2 = (char *)s2;
	str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (0);
	cpy(str, cp_s1, cp_s2);
	return (str);
}
