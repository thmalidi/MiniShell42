/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:48:02 by tmalidi           #+#    #+#             */
/*   Updated: 2023/07/14 14:01:34 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_elm(t_element **subparsing)
{
    t_element *tmp;
    t_element *list;
    
    list = *subparsing;
    while (list)
    {
        tmp = list;
        list = list->next;
        free(tmp->str); // Libération de la mémoire du contenu de l'élément
        free(tmp); // Libération de la mémoire de l'élément
    }
    free(list);
}