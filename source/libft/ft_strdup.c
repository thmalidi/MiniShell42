/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:48:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/20 15:03:03 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*sdup;
	size_t		len;
	int			i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	sdup = (char *)malloc(sizeof(char) * (len + 1));
	if (!sdup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		sdup[i] = ((char *)s)[i];
		i++;
	}
	sdup[i] = ((char *)s)[i];
	return (sdup);
}
