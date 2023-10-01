/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:22:26 by tmalidi           #+#    #+#             */
/*   Updated: 2023/10/01 15:31:51 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*space(char *str, int range)
{
	char	*f;
	char	*s;
	char	*tmp;

	f = ft_substr(str, 0, range);
	s = ft_substr(str + range, 0, ft_strlen(str + range));
	free(str);
	if (!f || !s)
		return (error_manager("space(ft_substr)", MALLOC), NULL);
	tmp = ft_strjoin(f, " ");
	if (!tmp)
		return (error_manager("space(ft_strjoin)", MALLOC), NULL);
	free(f);
	f = ft_strjoin(tmp, s);
	if (!f)
		return (error_manager("space(ft_strjoin)", MALLOC), NULL);
	return (free(s), free(tmp), f);
}

char	*put_space(char *str)
{
	int		i;

	i = 0;
	if (str[0] != 34 && str[0] != 39)
	{
		while (str && str[i])
		{
			while (str && str[i] && (str[i] == '<' || str[i] == '>'))
				i++;
			if (str && str[i] != ' ' && str[i] && i != 0 && between(str, i))
				str = space(str, i);
			while (str && str[i] && (str[i] != '<' && str[i] != '>'))
				i++;
			if (str && str[i] != ' ' && str[i] && between(str, i))
				str = space(str, i++);
		}
	}
	return (str);
}

int	count_symb_in(char *str)
{
	int	i;
	int	v;

	v = 0;
	i = 0;
	if (!str)
		return (1);
	if (str[0] != 34 && str[0] != 39)
	{
		while (str[i])
		{
			if (str[i++] == '<')
				v++;
		}
		if (v >= 3)
		{
			if (v == 4)
				return (error_manager("<", SYNTAX), 0);
			else if (v == 5)
				return (error_manager("<<", SYNTAX), 0);
			else
				return (error_manager("<<<", SYNTAX), 0);
		}
	}
	return (1);
}

int	count_symb_out(char *str)
{
	int	i;
	int	v;

	v = 0;
	i = 0;
	if (!str)
		return (1);
	if (str[0] != 34 && str[0] != 39)
	{
		while (str[i])
		{
			if (str[i++] == '>')
				v++;
		}
		if (v > 2)
		{
			if (v == 3)
				return (error_manager(">", SYNTAX), 0);
			else
				return (error_manager(">>", SYNTAX), 0);
		}
	}
	return (1);
}

int	check_in_outfile(t_big_list *arg)
{
	t_big_list	*tmp;
	t_element	*etmp;

	tmp = arg;
	if (!tmp->content)
		return (0);
	while (tmp)
	{
		if (tmp == NULL || !*tmp->pipelist)
			break ;
		etmp = *tmp->pipelist;
		while (etmp)
		{
			if (etmp->type != 5)
			{
				if (!count_symb_in(etmp->str) || !count_symb_out(etmp->str))
					return (free_elm(arg), free_lst(arg), 0);
				if (!potential_error(etmp, tmp))
					return (free_elm(arg), free_lst(arg), 0);
			}
			etmp = etmp->next;
		}
		tmp = tmp->next;
	}
	return (1);
}
