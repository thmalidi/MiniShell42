/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:26:33 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/01 15:16:57 by hgeffroy         ###   ########.fr       */
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
	t_pipelist	*temp;
	int			count;

	temp = pipelist;
	count = 0;
	while (temp /*&& type n'est pa une redir*/)
		count++;
	return (count);
		
}

/*
Retourne les tableau que execve prendra en argument.
Retourne NULL si ce n'est pas une commande existante.
*/
char	**gen_args(t_pipelist *pipelist)
{
	t_pipelist	*temp;
	char		**args;
	int			i;

	args = (char **)malloc(sizeof(char *) * (count_optn(pipelist) + 1));
	if (!args)
		return (NULL);
	temp = pipelist;
	i = 0;
	args[i] = ft_strdup(temp->elt);
	while (1 /*temp->type est soit un fichier soit un flag soit un dossier soit un truc inconnu, il faut s'arreter au premier truc inconnu*/)
	{
		args[i++] = ft_strdup(temp->elt);
		if (!args[i])
			return (/*Free des trucs*/ NULL);
		temp->next;
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