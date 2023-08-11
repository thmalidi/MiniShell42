/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:03:32 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/11 17:13:52 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *rp_trim(char *str)
{
	char *tmp;

	if (str[0] == 39 )
		tmp = ft_strtrim(str, "\'");
	else if (str[0] == 34)
		tmp = ft_strtrim(str, "\"");
	else
		tmp = ft_strdup(str);
	return (free(str), tmp);
	
}