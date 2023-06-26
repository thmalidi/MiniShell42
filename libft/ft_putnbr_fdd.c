/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fdd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:32:52 by tmalidi           #+#    #+#             */
/*   Updated: 2023/02/07 13:23:40 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	no_exept(int n, char *temp, int fd, int len)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		temp[i++] = (char)((n % 10) + 48);
		n = n / 10;
	}
	i -= 1;
	while (i >= 0)
	{
		if (!write(fd, &temp[i--], 1))
			return (-1);
		len++;
	}
	return (len);
}

int	ft_putnbr_fdd(int n, int fd)
{
	char	temp[12];
	int		len;

	len = 0;
	if (n == 0)
		return (write (fd, "0", 1));
	if (n == INT_MIN)
		return (write (fd, "-2147483648", 11));
	if (n < 0)
	{
		if (!write(fd, "-", 1))
			return (-1);
		len++;
		n = n * -1;
	}
	return (no_exept(n, temp, fd, len));
}
