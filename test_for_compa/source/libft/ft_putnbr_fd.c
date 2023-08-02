/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:32:52 by tmalidi           #+#    #+#             */
/*   Updated: 2022/11/15 13:32:58 by tmalidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	temp[12];
	int		i;

	i = 0;
	if (n == 0)
		write (fd, "0", 1);
	if (n == INT_MIN)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	while (n != 0)
	{
		temp[i++] = (char)((n % 10) + 48);
		n = n / 10;
	}
	i -= 1;
	while (i >= 0)
		write(fd, &temp[i--], 1);
}
