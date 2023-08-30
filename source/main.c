/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:40:49 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/30 13:01:39 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_return_value;

int only_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i++] != 32)
			return (1);
	}
	return (0);
}

void	manage_line(char *line, t_env **env)			//ajouter la fonctionde l'exec ici
{
 	t_big_list	*arg;
	
 	if (line)
 	{
		if (only_space(line))
		{
			arg = parsing(line, env);
			if (arg) 
			{
				splited_arg(arg);									//creation de la liste pour chaque pipe ici
				// plst(arg);
				g_return_value = exec(arg, env);
			}
		}
 	}
}

int	main(int ac, char **av, char **env)
{
	t_env				*envlst;
	char				*line;
	int					i;

	(void)ac;
	(void)av;
	i = 0;
	envlst = create_env(env);
	init_signals();
	g_return_value = 0;
 	while (1)
 	{
 		line = readline("\033[32mMinishell>\033[0m");
		if (!line)
		{
			free(line);
			return (g_return_value);
		}
		add_history(line);
 		manage_line(line, &envlst);
 		i++;
 	}
	// rl_clear_history();
 	return (g_return_value);
}

/*int main()
{
	t_big_list	**arg;
	char		*line;
	int i;
	
	i = 0;
	while(i < 3)											//limite pour tester les leaks remplacer par "while(1)" pour boucle infini
	{
		line = readline("\033[32mMinishell>\033[0m");
		arg = parsing(line);
		if (arg)
		{
			splited_arg(arg);
			plst(arg);									//decommenter pour afficher les element de la liste
			free_elm(arg);
			free_lst(arg);
		}
		i++;
	}
}*/
