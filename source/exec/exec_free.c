/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:17:07 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/08 13:49:07 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	free_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	return ;
// }

/*
Enleve les elts correspondants aux redirections apres avoir check une redirection.
*/
t_element	*remove_files(t_element *elt)
{
	t_element	*res;
	t_element 	*tmp1;
	t_element	*tmp2;

	if (elt->previous)
	{
		res = elt->previous;
		if (elt->next->next)
			res->next = elt->next->next;
		else
			res->next = NULL;
	}
	else if (elt->next->next)
		res = elt->next->next;
	else // Truc du genre < out sans rien d'autre
		res = NULL;
	tmp1 = elt;
	tmp2 = elt->next;
	free(tmp1->str);
	free(tmp1);
	free(tmp2->str);
	free(tmp2);
	// printf("Retour de remove files : %s\n", res->str);
	return (res);
}

void	free_element(t_element *elt)
{
	t_element	*tmp1;
	t_element	*tmp2;
	
	tmp2 = elt;
	if (!tmp2)
		return ;
	tmp1 = elt->next;
	while (tmp1)
	{
		free(tmp2->str);
		free(tmp2);
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	free(tmp2->str);
	free(tmp2);
}

void	free_big_list(t_big_list *list)
{
	t_big_list	*tmp1;
	t_big_list	*tmp2;

	tmp2 = list;
	if (!tmp2)
		return ;
	tmp1 = list->next;
	while (tmp1)
	{
		free(tmp2->content);
		free_element(*(tmp2->pipelist));
		free(tmp2);
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	free(tmp2->content);
	free_element(*(tmp2->pipelist));
	free(tmp2);
}
