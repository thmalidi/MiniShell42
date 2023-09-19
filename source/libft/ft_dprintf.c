/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:46:43 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/19 08:54:04 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprints(char *buffer, char *str, int j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		buffer[j + i] = str[i];
		i++;
	}
	return (ft_strlen(str));
}

int	str_manager(char *buffer, char *str, va_list args, int mode)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '%')
			mode++;
		else if (mode % 2 == 1)
		{
			if (str[i] == 's')
			{
				j += ft_dprints(buffer, va_arg(args, char *), j);
				mode++;
			}
		}
		else
			buffer[j++] = str[i];
	}
	return (j);
}

int	ft_dprintf(int fd, char *str, ...)
{
	va_list		args;
	char		buffer[4096];
	int			mode;
	int			val;

	if (write(fd, 0, 0) != 0)
		return (-1);
	val = 0;
	mode = 0;
	va_start(args, str);
	val += str_manager(buffer, str, args, mode);
	va_end(args);
	buffer[val] = '\0';
	write(fd, buffer, val);
	return (val);
}
