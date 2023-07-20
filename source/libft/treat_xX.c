/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:09:32 by tmalidi           #+#    #+#             */
/*   Updated: 2023/02/07 13:23:02 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	treat_x(char c, va_list pmt)
{
	long int	e;

	e = va_arg(pmt, int);
	if (e < 0)
		e = 4294967296 - (e * -1);
	if (c == 'X')
		return (ft_putnbr_base(e, "0123456789ABCDEF"));
	else
		return (ft_putnbr_base(e, "0123456789abcdef"));
}
