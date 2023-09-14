/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:54:00 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/14 10:39:09 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

int	ft_dprintf(int fd, char *str, ...)
{
	va_list		args;
	char		buffer[4096];
	int			mode;
	int			i;
	int			j;

	if (write(fd, 0, 0) != 0)
		return (-1);
	i = 0;
	j = 0;
	mode = 0;
	va_start(args, str);
	while (str[i])
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
			else
				write(2, "Mode not managed yet\n", 22);
		}
		else
		{
			buffer[j] = str[i];
			j++;
		}
		i++;
	}
	va_end(args);
	buffer[j] = '\0';
	write(fd, buffer, j);
	return (j);
}
