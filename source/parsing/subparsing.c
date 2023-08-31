/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:59:50 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/31 08:47:01 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_element	*ft_lstnew_e(char *str)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!new)
		return (0);
	new->str = ft_strdup(str);
	new->type = -2;
	new->next = NULL;
	return (new);
}

void	space_process(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		tab[i] = put_space(tab[i]);
		i++;
	}
}

void	splited_arg(t_big_list *arg)
{
	char		**tab;
	t_big_list	*tmp;
	int			i;
	int			n;

	tmp = arg;
	while (tmp)
	{
		tmp->pipelist = malloc(sizeof(t_element *)); //proteger...
		*tmp->pipelist = NULL;
		tmp->content = put_space(tmp->content);
		tab = ft_split(tmp->content, ' ');
		i = 0;
		while (tab[i])
			ft_lstadd_back_e(tmp->pipelist, ft_lstnew_e(tab[i++]));
		free_tab(tab);
		tmp = tmp->next;
	}
	tmp = arg;
	n = 1;
	while (tmp)
	{
		subparsing(tmp->pipelist, tmp, n++);
		tmp = tmp->next;
	}
}
