/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:40:49 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/06 10:56:30 by tmalidi          ###   ########.fr       */
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

/*void	handle_signal(int sig)
{
	if (sig == SIGINT)
		printf("\n\033[32mMinishell>\033[0m");
}

void	init_sa(struct sigaction *sa)
{
	sa->sa_handler = handle_signal;
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = 0;
	if (sigaction(SIGINT, sa, NULL) == -1) 
	{
		perror("Erreur lors de la configuration du gestionnaire de signal");
		exit(EXIT_FAILURE);
	}
}*/


/////



/*void	manage_line(char *line, t_history **history)			//ajouter la fonctionde l'exec ici
{
	t_big_list	**arg;

	if (!ft_strncmp(line, "history", ft_strlen(line)) && ft_strlen(line) != 0)
		plst_h(history);
	else if (ft_strlen(line) != 0)
	{
		arg = parsing(line);
		if (arg) 
		{
			splited_arg(arg);									//creation de la liste pour chaque pipe ici
			free_elm(arg);
			free_lst(arg);
		}
	}
}

int	main(void)
{
	//struct sigaction	sa;
	t_history			**history;
	char				*line;
	int					i;

	//init_sa(&sa);
	i = 0;
	history = malloc(sizeof(t_history *));
	if (!history)
		return (0);
	*history = NULL;
	while (i < 3)
	{
		line = readline("\033[32mMinishell>\033[0m");
		add_to_history(history, line);
		manage_line(line, history);
		i++;
	}
	free_history(history);
	return (0);
}*/

