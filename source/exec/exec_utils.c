/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:03:53 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/11 15:39:38 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Close les n premiers fd.
*/
void	close_fd(int *fd, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (fd[i])
			close (fd[i]);
		i++;
	}
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

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		printf("tab[%d] = %s\n", i, tab[i]);
}

void	print_tab_int(int *tab, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		printf("tab[%d] = %d\n", i, tab[i]);
}

int	is_builtin(char *cmd)
{	
	int			i;
	const char	*builtins[] = {"cd", "echo", "env", "exit", \
							"export", "pwd", "unset", NULL};

	i = -1;
	while (builtins[++i])
	{
		if (!strcmp(cmd, builtins[i]))
			return (i);
	}
	return (-1);
}

// void	close_all(int *fd)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < 6)
// 	{
// 		if (fd[i] > 0)
// 			close (fd[i]);
// 	}
// 	return ;
// }

// void	close_inpipe(int *fd)
// {
// 	if (fd[0] > 0)
// 		close (fd[0]);
// 	if (fd[1] > 0)
// 		close (fd[1]);
// 	if (fd[4] > 0)
// 		close (fd[4]);
// 	if (fd[5] > 0)
// 		close (fd[5]);
// 	fd[4] = 0;
// 	fd[5] = 0;
// }