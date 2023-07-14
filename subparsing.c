/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:59:50 by tmalidi           #+#    #+#             */
/*   Updated: 2023/07/14 14:07:17 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void printf_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        printf(">>>%s\n", tab[i++]);
}

void pte(t_element **list)
{
    t_element *tmp;

    tmp = *list;
    while (tmp)
    {
        printf(">%s<\n", tmp->str);
        tmp = tmp->next;
    }
}

t_element	*ft_lstnew_e(char *str)
{
    t_element *new;
    
    new = malloc(sizeof(t_element));
	if (!new)
		return (0);
    new->str = ft_strdup(str);
    new->type = -2;
    new->next = NULL;
    return (new);
}

void    splited_arg(t_list **arg)
{
    char **tab;
    t_list *tmp;
    int     i;
    
    tmp = *arg;
    while(tmp)
    {
        i = 0;
        tmp->subparsing = malloc(sizeof(t_element *));
        *tmp->subparsing = NULL;
        tab = ft_split(tmp->content, ' ');
        while (tab[i])
            ft_lstadd_back_e(tmp->subparsing, ft_lstnew_e(tab[i++]));
        pte(tmp->subparsing);
        free(tab);
        tmp = tmp->next;
    }
}

