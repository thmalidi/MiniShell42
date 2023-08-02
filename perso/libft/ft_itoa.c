/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:11:57 by tmalidi           #+#    #+#             */
/*   Updated: 2023/02/07 13:21:05 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbrlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i += 1;
		n *= -1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i - 1);
}

static void	mk_final(int i, char *str, long int t)
{
	str[i - 1] = '\0';
	i -= 2;
	while (i >= 0 && t > 0)
	{
		str[i] = t % 10 + '0';
		t /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	t;

	t = n;
	i = nbrlen(t) + 1;
	if (t == 0)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * i);
	if (str == NULL)
		return (0);
	if (t < 0)
	{
		str[0] = '-';
		t = t * -1;
	}
	mk_final(i, str, t);
	return (str);
}
