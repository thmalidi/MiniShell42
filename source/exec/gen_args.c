/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:26:33 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/02 14:10:19 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*
Retourne le nombre d'option pour la premiere commande.
Faire des tests sur bash pour voir comment ca se passe si on met des options apres une redir ou autre. Les options sont forcement juste apres la commande.
Il semblerait qu'il faille ajouter tous les fichiers et option jusqu' a ce qu'on croise autre chose (genre redir)
*/
int	count_optn(t_pipelist *pipelist)
{
	t_pipelist	*tmp;
	int			count;

	tmp = pipelist;
	count = 0;
	while (tmp)
	{
		if (tmp->type < 5 && tmp->type > 0)
		{
			tmp = tmp->next;
			tmp = tmp->next;
		}
		else
		{
			tmp = tmp->next;
			count++;
		}
	}
	return (count);
		
}

/*
Retourne les tableau que execve prendra en argument.
Retourne NULL si ce n'est pas une commande existante.
Attention probleme si 2 signes de redir a la suite !! A gerer au parsing ?
*/
char	**gen_args(t_pipelist *pipelist)
{
	t_pipelist	*tmp;
	char		**args;
	int			i;

	args = (char **)malloc(sizeof(char *) * (count_optn(pipelist) + 1));
	if (!args)
		return (NULL);
	tmp = pipelist;
	i = 0;
	args[i] = ft_strdup(tmp->elt);
	while (tmp && tmp->type != 8) //Ici, on peut potentiellement gerer le cas ou il n'y a aucune commande dans le pipe. OU avant ?
		tmp = tmp->next;
	// Il va falloir recuperer la commande ici et la mettre au debut de args. 
	while (tmp)
	{
		if (tmp->type > 0 && tmp->type < 5)
			tmp = tmp->next->next;
		else
		{
			args[i++] = ft_strdup(tmp->elt);
			if (!args[i])
				return (/*Free des trucs*/ NULL);
			tmp->next;
		}
	}
	args[i] = NULL;
	return (args);
}


// #include <stddef.h>
// #include <stdlib.h>
// int main(int ac, char **av, char **env)
// {
// 	char **test;

// 	test = (char **)malloc(sizeof(char *) * 5);

// 	test[0] = strdup("/bin/ls");
// 	test[1] = strdup("exec.h");
// 	test[2] = strdup("a");
// 	test[3] = strdup("e");
// 	test[4] = NULL;
	
// 	execve(test[0], test, env);
// 	puts("\n");
// 	//perror("\n");
// 	return (0);
// }