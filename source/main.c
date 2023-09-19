/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:35:39 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/19 15:38:29 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_return_value;

int	only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] != 32)
			return (1);
	}
	return (0);
}

void	manage_line(char *line, t_env **env)
{
	t_big_list	*arg;

	if (line)
	{
		if (only_space(line))
		{
			arg = parsing(line, env);
			if (arg)
			{
				splited_arg(arg);
				if (check_in_outfile(arg) && g_return_value == 0)
					exec(arg, env);
			}
		}
	}
}

int	main(int ac, char **av, char **env)
{
	t_env				*envlst;
	char				*line;

	(void)ac;
	(void)av;
	envlst = create_env(env);
	g_return_value = 0;
	while (1)
	{
		init_signals();
		line = readline("\001\033[32m\002Minishell>\001\033[0m\002");
		if (!line)
		{
			free(line);
			printf("\n");
			free_env(envlst);
			return (g_return_value);
		}
		add_history(line);
		manage_line(line, &envlst);
		free(line);
	}
	free_env(envlst);
	rl_clear_history();
	return (g_return_value);
}
