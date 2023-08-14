/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:22:26 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/14 18:06:46 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_in_outfile(t_big_list *arg)
{
	t_big_list *tmp;
	t_element *etmp;
	
	tmp = arg;
	while (tmp)
	{
		if (tmp == NULL)
			break ;
		etmp = *tmp->pipelist;
		while (etmp)
		{
			if ((etmp->type == 1 || etmp->type == 2 || etmp->type == 3 || etmp->type == 4) && etmp->next == NULL)
			{
				if (tmp->next == NULL)
					return (printf("parse error near `|'\n"), return_value = 130, free_elm(arg), free_lst(arg), 0);
				else
					return (printf("parse error near `|'\n"), return_value = 130, free_elm(arg), free_lst(arg), 0);
			}
			etmp = etmp->next;
		}
		tmp = tmp->next;
	}
	return (1);
}