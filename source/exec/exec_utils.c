/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:40:31 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/29 08:22:54 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_whitespace(char *str)
{
	int	i;

	if (!str)
		return (YES);
	i = 0;
	while (str[i])
	{
		if (!(str[i] > 8 && str[i] < 14) || str[i] == 32)
			return (NO);
		i++;
	}
	return (YES);
}

int	element_len(t_element *list)
{
	int			len;
	t_element	*tmp;

	len = 0;
	tmp = list;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	is_builtin(char *cmd)
{
	int			i;
	const char	*builtins[] = {"cd", "echo", "env", "exit", \
							"export", "pwd", "unset", NULL};

	i = -1;
	if (!cmd)
		return (-1);
	while (builtins[++i])
	{
		if (!strcmp(cmd, builtins[i]))
			return (i);
	}
	return (-1);
}

int	len_data(t_data *data)
{
	int		len;
	t_data	*tmp;

	len = 0;
	tmp = data;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
