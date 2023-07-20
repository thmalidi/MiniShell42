/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:49:31 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/14 16:50:01 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*cp_s;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (0);
	cp_s = (char *)s;
	while (cp_s[i])
	{
		str[i] = (*f)(i, cp_s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
