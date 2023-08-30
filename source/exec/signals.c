/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:05:15 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/30 12:31:17 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	
	// (void)sig;
	// printf("\n");
	// rl_replace_line("", 0);
	// rl_on_new_line();
	// rl_redisplay();
 }

void	child_handler(int sig)
{
	(void)sig;
	
	// if (sig == SIGINT)
	// {
	// 	return_value = 130;
	// 	printf("\n");
	// }
	// else if (sig == SIGQUIT)
	// {
	// 	return_value = 131;
	// 	printf("Quit (core dumped)\n");
	// }
}

void	hd_handler(int sig)
{
	(void)sig; //A garder !
	//exit(130);
}

void	init_signals(void)
{
	// signal(SIGINT, SIG_IGN);
	// signal(SIGQUIT, SIG_IGN);
	// signal(SIGINT, &rl_handler);
}
