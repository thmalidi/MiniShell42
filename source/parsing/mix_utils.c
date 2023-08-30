/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:22:26 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/30 17:08:26 by tmalidi          ###   ########.fr       */
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
	tmp = ft_strjoin(f, " ");
	free(f);
	f = ft_strjoin(tmp, s);
	return (free(s), free(tmp), f);
}

char	*put_space(char *str)
{
	int		i;
	char	*final;

	i = 0;
	final = ft_strdup(str);
	free(str);
	if (final[0] != 34 && final[0] != 39)
	{
		while (final[i])
		{
			while (final[i] && (final[i] == '<' || final[i] == '>'))
				i++;
			if (final[i] != ' ' && final[i] && i != 0 && between(final, i))
				final = space(final, i);
			while (final[i] && (final[i] != '<' && final[i] != '>'))
				i++;
			if (final[i] != ' ' && final[i] && between(final, i))
				final = space(final, i++);
		}
	}
	return (final);
}

int	count_symb_in(char *str)
{
	int	i;
	int	v;

	v = 0;
	i = 0;
	if (str[0] != 34 && str[0] != 39)
	{
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
	}
	return (1);
}

int	count_symb_out(char *str)
{
	int	i;
	int	v;

	v = 0;
	i = 0;
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
				return (printf("parse error near `>'\n"), 0);
			else
				return (printf("parse error near `>>'\n"), 0);
		}
	}
	return (1);
}

int	check_in_outfile(t_big_list *arg)
{
	t_big_list	*tmp;
	t_element	*etmp;

	tmp = arg;
	while (tmp)
	{
		if (tmp == NULL)
			break ;
		etmp = *tmp->pipelist;
		while (etmp)
		{
			if (!count_symb_in(etmp->str) || !count_symb_out(etmp->str))
				return (g_return_value = 130, 0);
			if (!potential_error(etmp, tmp))
				return (0);
			etmp = etmp->next;
		}
		tmp = tmp->next;
	}
	return (1);
}
