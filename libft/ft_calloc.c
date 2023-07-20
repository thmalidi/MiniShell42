/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:01:22 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/10 14:01:26 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;

	if (count == ULONG_MAX)
		return (NULL);
	tab = malloc(count * size);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}
