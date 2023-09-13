/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subparsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:15:36 by tmalidi           #+#    #+#             */
/*   Updated: 2023/09/13 14:03:34 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*joined;

	if (!path)
		return (0);
	if (access(cmd, X_OK) == 0)
		return (1);
	tmp = ft_strjoin("/", cmd);
	while (*path)
	{
		joined = ft_strjoin(*path, tmp);
		if (access(joined, X_OK) == 0)
			return (free(tmp), free(joined), 1);
		free(joined);
		path++;
	}
	return (free(tmp), 0);
}

int	is_builtins(char *str)
{
	if (!ft_strncmp("echo", str, ft_strlen(str)))
		return (1);
	if (!ft_strncmp("cd", str, ft_strlen(str)))
		return (1);
	if (!ft_strncmp("pwd", str, ft_strlen(str)))
		return (1);
	if (!ft_strncmp("unset", str, ft_strlen(str)))
		return (1);
	if (!ft_strncmp("env", str, ft_strlen(str)))
		return (1);
	if (!ft_strncmp("export", str, ft_strlen(str)))
		return (1);
	if (!ft_strncmp("exit", str, ft_strlen(str)))
		return (1);
	return (0);
}

int	is_ok(t_big_list **a)
{
	t_big_list	*test;
	t_element	*tmp;

	test = *a;
	while (test)
	{
		tmp = *test->pipelist;
		while (tmp)
		{
			if (!scan_cmd(tmp->str))
				return (0);
			tmp = tmp->next;
		}
		test = test->next;
	}
	return (1);
}

void	asign_type(t_element *tmp, t_big_list *arg, int n)
{
	if (!ft_strncmp("<", tmp->str, ft_strlen(tmp->str)))
		tmp->type = 1;
	else if (!ft_strncmp("<<", tmp->str, ft_strlen(tmp->str)))
	{
		arg->here_doc = n;
		tmp->type = 2;
	}
	else if (!strncmp(">", tmp->str, ft_strlen(tmp->str)))
		tmp->type = 3;
	else if (!strncmp(">>", tmp->str, ft_strlen(tmp->str)))
		tmp->type = 4;
	else
		tmp->type = 5;
	/*else if (tmp->str[0] == '-')
		tmp->type = 5;
	else if (is_builtins(tmp->str))
	{
		arg->builtin = 1;
		tmp->type = 7;
	}
	else
		tmp->type = -1;*/
}

int	subparsing(t_element **subparsing, t_big_list *arg, int n)
{
	int			i;
	t_element	*tmp;
	char		**envp;

	i = 0;
	arg->here_doc = 0;
	tmp = *subparsing;
	envp = ft_split(getenv("PATH"), ':');
	while (tmp)
	{
		clean_str(tmp->str, 1);
		asign_type(tmp, arg, n);
		//tmp->str = free_trim(tmp->str);
		tmp->str = end_clean(tmp->str, tmp);
		tmp = tmp->next;
		i++;
	}
	return (free_tab(envp), 1);
}
