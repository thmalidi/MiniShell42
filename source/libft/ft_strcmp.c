/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:31:06 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/13 10:45:14 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	if (!s1)
		return(s2[0]);
	else if (!s2)
		return(s1[0]);
	else if (!s1 && !s2)
		return (0);
	while(s1[++i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}
