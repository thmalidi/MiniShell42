/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:40:49 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/14 18:12:10 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int return_value = 0;

void	manage_line(char *line, t_env **env)			//ajouter la fonctionde l'exec ici
{
	t_big_list			*arg;
	
	if (ft_strlen(line) != 0)
	{
		arg = parsing(line, env);
		if (arg) 
		{
			splited_arg(arg);								//creation de la liste pour chaque pipe ici
			check_in_outfile(arg);
			/*if(!is_ok(arg))
				printf("faut pas que ca passe\n");*/
			free_elm(arg);
			free_lst(arg);
		}
	}
}

void shab_env(t_env *env)
{
	t_env *tmp;

	tmp = env;
	while (tmp)
	{
		if (!tmp)
			return ;
		printf("var = %s | value = %s\n", tmp->var,tmp->value);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av, char **env)
{
	
	char				*line;
	int					i;
	t_env				*envlst;
	
	(void)ac;
	(void)av;
	i = 0;
	envlst = create_env(env);
	//shab_env(envlst);
	while (i < 3)
	{
		line = readline("\033[32mMinishell>\033[0m");
		add_history(line);
		manage_line(line, &envlst);
		i++;
	}
	printf("%d", return_value);
	rl_clear_history();
	return (0);
}

