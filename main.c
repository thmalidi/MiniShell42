/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:40:49 by tmalidi           #+#    #+#             */
/*   Updated: 2023/06/28 16:44:34 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
        if (!ft_strncmp(line, "history", ft_strlen(line)))  //ecrire "history une foi minishell lancer pour afficher l'historique"
            plst_h(history);
		add_to_history(history, line);
		arg = parsing(line);
		//plst(arg);										//decommenter pour afficher les element de la liste
		free_lst(arg);
		i++;
	}
    free_history(history);
	//plst_h(history);
}