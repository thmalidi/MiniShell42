/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:38:37 by tmalidi           #+#    #+#             */
/*   Updated: 2023/06/26 17:11:51 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*tab;
	int		r;

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
