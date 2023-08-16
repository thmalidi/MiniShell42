/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:40:49 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/16 16:47:27 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
void print_envp(char **envp)
{
	while (*envp)
		printf("%s\n", *envp++);
}

int main()
{
	t_list **arg;
	t_history **history;
	char *line;
	int i = 0;
	
	history = malloc(sizeof(t_history *));
	*history = NULL;
	while(i < 3)											//limite pour tester les leaks remplacer par "while(1)" pour boucle infini
	{
		line = readline("\033[32mMinishell>\033[0m");
		if (!ft_strncmp(line, "history", ft_strlen(line)))  //ecrire "history une fois minishell lancer pour afficher l'historique"
			plst_h(history);
		add_to_history(history, line);
		arg = parsing(line);
		if (arg)
		{
			splited_arg(arg);
			//plst(arg);									//decommenter pour afficher les element de la liste
			free_elm(arg);
			free_lst(arg);
		}
		i++;
	}
	free_history(history);
	//plst_h(history);
}*/

// void	handle_signal(int sig)
// {
// 	if (sig == SIGINT)
// 		printf("\n\033[32mMinishell>\033[0m");
// }

// void	init_sa(struct sigaction *sa)
// {
// 	sa->sa_handler = handle_signal;
// 	sigemptyset(&sa->sa_mask);
// 	sa->sa_flags = 0;
// 	if (sigaction(SIGINT, sa, NULL) == -1) 
// 	{
// 		perror("Erreur lors de la configuration du gestionnaire de signal");
// 		exit(EXIT_FAILURE);
// 	}
// }

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
				exec(arg, env);
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
 	while (1)
 	{
 		line = readline("\033[32mMinishell>\033[0m");
		add_history(line);
 		manage_line(line, &envlst);
 		i++;
 	}
	rl_clear_history();
 	return (0);
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
