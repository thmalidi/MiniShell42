/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:35:42 by tmalidi           #+#    #+#             */
/*   Updated: 2023/02/07 14:20:54 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ret_ind(const char *str)
{
	int	i;

	i = 0;
	while (((str[i] >= 9 && str[i] <= 13)
			|| (str[i] == 32)))
		i++;
	return (i);
}

static int	char_to_int(const char *str, int i, int sign)
{
	long long int	r;

	r = 0;
	while (str [i] <= '9' && str[i] >= '0')
	{
		if (r != ((r * 10 + (((str[i] - 48)) * sign)) / 10))
			return (((sign + 1) / 2) / -1);
		r = r * 10;
		r += str[i] - 48;
		i++;
	}
	return (r);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	r;
	int	ind;
	int	sign;

	i = 0;
	r = 0;
	(void)r;
	(void)i;
	sign = 1;
	ind = ret_ind(str);
	if (str[ind] == '+')
		return (char_to_int(str, ind + 1, sign));
	else if (str[ind] == '-')
	{
		sign -= 1;
		return (char_to_int(str, ind + 1, sign) * -1);
	}
	else if (str[ind] >= '0' && str[ind] <= '9')
		return (char_to_int(str, ind, sign));
	return (0);
}
