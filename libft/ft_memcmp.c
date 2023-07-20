/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:50:36 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/08 17:50:41 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cp_s1;
	const unsigned char	*cp_s2;

	cp_s1 = s1;
	cp_s2 = s2;
	while (cp_s1 && n)
	{
		if (*cp_s1 != *cp_s2)
			return (*cp_s1 - *cp_s2);
		n--;
		cp_s1++;
		cp_s2++;
	}
	if (n)
		return (*cp_s1 - *cp_s2);
	return (0);
}
