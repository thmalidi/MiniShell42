/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:27:03 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/14 07:34:57 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_putchar(int c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	printf_putstr(const char *str, int fd)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
