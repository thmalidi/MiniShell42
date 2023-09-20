/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_func3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 07:39:23 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/20 07:43:26 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_quotes(char *str)
{
	ft_dprintf(2, " unexpected EOF while looking for matching '%s'\n", str);
	g_return_value = 2;
	return (0);
}