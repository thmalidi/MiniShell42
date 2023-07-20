/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 08:56:43 by tmalidi           #+#    #+#             */
/*   Updated: 2023/06/26 16:17:24 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*cp_s;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if ((size_t)ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if ((size_t)ft_strlen(s) < start)
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	if (ft_strlen(s) > start)
	{
		cp_s = (char *)s + start;
		while (cp_s[i] && (size_t)i < len)
		{
			str[i] = cp_s[i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
