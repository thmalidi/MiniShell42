/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexaP.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:04:11 by tmalidi           #+#    #+#             */
/*   Updated: 2023/02/07 13:22:51 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_writebaseu(unsigned long lnbr, char *base)
{
	int		c;
	int		i;
	char	tab[34];
	char	cp_tab[34];

	i = 0;
	c = 0;
	while (lnbr > 0)
	{
		tab[i] = base[lnbr % 16];
		lnbr = lnbr / 16;
		i++;
	}
	while (i > 0)
	{
		cp_tab[c] = tab[i - 1];
		i--;
		c++;
	}
	cp_tab[c] = '\0';
	return (write(1, cp_tab, ft_strlen(cp_tab)) + 2);
}

int	ft_putnbr(unsigned long nbr)
{
	if (!write(1, "0x", 2))
		return (-1);
	if (nbr == 0)
		return (write(1, "0", 1) + 2);
	return (ft_writebaseu(nbr, "0123456789abcdef"));
}
