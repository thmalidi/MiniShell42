/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:26:33 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/30 08:40:58 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while (temp /*&& type est un fichier ou une optn*/)
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
	while (1 /*temp->type est soit un fichier soit un flag soit un dossier*/)
	{
		args[i++] = ft_strdup(temp->elt);
		if (!args[i])
			return (/*Free des trucs*/ NULL);
		temp->next;
	}
	return (args);
}