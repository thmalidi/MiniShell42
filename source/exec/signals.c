/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:05:15 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/14 14:37:49 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
SIGINT : ctrl-C
SIGQUIT : ctrl-\
Si rl sort NULL, c’est ctrl-D : car ctrl-D est un EOF pas un signal.
On a 3 handlers a faire : pour les hd, pour les childs et pour le parent.
*/

#include "minishell.h"

void	parent_handler_int(int sig)
{
	(void)sig;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	get_signal_parent(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, &parent_handler_int);
	signal(SIGQUIT, SIG_IGN);
}
