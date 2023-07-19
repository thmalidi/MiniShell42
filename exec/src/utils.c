/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:03:53 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/19 08:43:06 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	close_all(int *fd)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (fd[i] > 0)
			close (fd[i]);
	}
	return ;
}

void	close_inpipe(int *fd)
{
	if (fd[0] > 0)
		close (fd[0]);
	if (fd[1] > 0)
		close (fd[1]);
	if (fd[4] > 0)
		close (fd[4]);
	if (fd[5] > 0)
		close (fd[5]);
	fd[4] = 0;
	fd[5] = 0;
}