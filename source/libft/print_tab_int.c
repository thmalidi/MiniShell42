/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:41:18 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/24 10:42:00 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_tab_int(int *tab, int n)
{
	int	i;

	if (!tab || n < 0)
		return ;
	i = -1;
	while (++i < n)
		printf("tab[%d] = %d\n", i, tab[i]);
}
