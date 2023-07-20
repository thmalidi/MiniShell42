/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:58:26 by tmalidi           #+#    #+#             */
/*   Updated: 2023/07/20 17:53:06 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_history_content(t_history *history)
{
    t_history *temp;
    
    while (history != NULL)
    {
        temp = history;
        history = history->next;
        free(temp->content); // Libération de la mémoire du contenu de l'élément
        free(temp); // Libération de la mémoire de l'élément
    }
    free(history);
}

void free_history(t_history **history)
{
    free_history_content(*history);
    free(history);
}

void free_lst_content(t_big_list *a)
{
    while (a != NULL)
    {
        t_big_list *temp = a;
        a = a->next;
        //free(a->subparsing);
        free(temp->content); // Libération de la mémoire du contenu de l'élément
        free(temp); // Libération de la mémoire de l'élément
    }
    free(a);
}

void free_lst(t_big_list **a)
{
    free_lst_content(*a);
    free(a);
}

void free_tab(char **tab)
{
    int i;

    i = 0;
    while(tab[i])
        free(tab[i++]);
    free(tab);
}