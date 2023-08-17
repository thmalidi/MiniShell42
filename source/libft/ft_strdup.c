/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:38:37 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/16 16:50:55 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*tab;
	int		r;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (0);
	r = 0;
	while (s1[r])
	{
		tab[r] = s1[r];
		r++;
	}
	tab[r] = '\0';
	return (tab);
}
