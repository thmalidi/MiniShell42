/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:27:36 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/17 13:32:17 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	printgc(char ltr, va_list arg)
{
	unsigned long	ad;

	if (ltr == 's')
		return (treat_s(arg));
	else if (ltr == 'c')
		return (ft_putchar_fdd(va_arg(arg, int), 1));
	else if (ltr == 'd' || ltr == 'i')
		return (ft_putnbr_fdd(va_arg(arg, int), 1));
	else if (ltr == 'x' || ltr == 'X')
		return (treat_x(ltr, arg));
	else if (ltr == 'u')
		return (treat_u(arg));
	else if (ltr == 'p')
	{
		ad = (unsigned long)va_arg(arg, unsigned long);
		return (ft_putnbr(ad));
	}
	else
		return (write(1, &ltr, 1));
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			len;
	va_list		arg;
	int			init_mem;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (write(1, 0, 0) != 0)
			return (-1);
		init_mem = len;
		if (str[i] == '%' && str[i + 1] != '\0')
			len += printgc(str[++i], arg);
		else if (str[i] != '%' && str[i])
			len += write(1, &str[i], 1);
		i++;
		if (init_mem > len)
			return (-1);
	}
	va_end(arg);
	return (len);
}
