/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:05:15 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/12 11:26:19 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

/*
SIGINT : ctrl-C
SIGQUIT : ctrl-\
Si rl sort NULL, c’est ctrl-D : car ctrl-D est un EOF pas un signal.
On a 3 handlers a faire : pour les hd, pour les childs et pour le parent.
*/

#include "minishell.h"

void	rl_handler(int sig)
{
	(void)sig;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	child_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_return_value = 130;
		printf("\n");
	}
	else if (sig == SIGQUIT)
	{
		g_return_value = 131;
		printf("Quit (core dumped)\n");
	}
}

void	hd_handler(int sig)
{
	(void)sig;
	printf("\n");
	exit(130);
}

void	ignore_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	init_signals(void)
{
	ignore_signals();
	signal(SIGINT, &rl_handler);
}
