/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:16:11 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/24 08:14:43 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_blank(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	res;
	long long int	pres;

	i = 0;
	while (is_blank(str[i]) == 1)
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		pres = res;
		res = res * 10 + str[i] - '0';
		if (pres != res / 10)
			return ((sign + 1) / -2);
		i++;
	}
	return ((int)(sign * res));
}
