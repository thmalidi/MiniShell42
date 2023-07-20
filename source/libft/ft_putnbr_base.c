/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:17:47 by tmalidi           #+#    #+#             */
/*   Updated: 2023/02/07 13:24:21 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	len_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

static int	ft_writebase(long int lnbr, int l_base, char *base)
{
	int	i;
	int	c;
	int	tab[34];

	i = 0;
	c = 0;
	while (lnbr > 0)
	{
		tab[i] = base[lnbr % l_base];
		lnbr = lnbr / l_base;
		i++;
		c++;
	}
	while (i > 0)
	{
		ft_putchar(tab[i - 1]);
		i--;
	}
	return (c);
}

int	ft_putnbr_base(long int nbr, char *base)
{
	long int	lnbr;

	lnbr = nbr;
	if (nbr == 0)
		return (write(1, "0", 1));
	if (lnbr < 0)
	{
		ft_putchar('-');
		lnbr = lnbr * -1;
	}
	return (ft_writebase(lnbr, len_base(base), base));
}
