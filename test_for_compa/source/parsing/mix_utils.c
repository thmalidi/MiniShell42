/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:22:26 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/15 09:50:28 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int count_symb_in(char *str)
{
	int i;
	int v;

	v = 0;
	i = 0;
	while (str[i])
	{
		if (str[i++] == '<')
			v++;
	}
	if (v > 3)
	{
		if (v == 4)
			return (printf("parse error near `<'\n"), 0);
		else if (v == 5)
			return (printf("parse error near `<<'\n"), 0);
		else
			return (printf("parse error near `<<<'\n"), 0);
	}
	return (1);
}

int count_symb_out(char *str)
{
	int i;
	int v;

	v = 0;
	i = 0;
	while (str[i])
	{
		if (str[i++] == '>')
			v++;
	}
	if (v > 2)
	{
		if (v == 4)
			return (printf("parse error near `>'\n"), 0);
		else
			return (printf("parse error near `>>'\n"), 0);
	}
	return (1);
}

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
			if (!count_symb_in(etmp->str) || !count_symb_out(etmp->str))
				return (return_value = 130, 0);
			if ((etmp->type == 1 || etmp->type == 2 || etmp->type == 3 || etmp->type == 4) && etmp->next == NULL)
			{
				if (tmp->next == NULL)
					return (printf("parse error near `|'\n"), return_value = 130, 0);
				else
					return (printf("parse error near `|'\n"), return_value = 130, 0);
			}
			etmp = etmp->next;
		}
		tmp = tmp->next;
	}
	return (1);
}