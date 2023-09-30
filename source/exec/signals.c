/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:41:56 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/29 08:23:08 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rl_handler(int sig)
{
	(void)sig;
	g_return_value = 130;
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
	rl_replace_line("", 0);
	g_return_value = 130;
	close(STDIN_FILENO);
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
