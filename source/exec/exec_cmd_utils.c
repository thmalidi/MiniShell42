/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:01:48 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/23 15:37:41 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_cmdwpath(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return (-1);
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (0);
		i++;
	}
	return (-1);
}

char	**is_path(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

// char	**is_path(t_env *env)
// {
// 	int		i;
// 	char	*tmp;
// 	char	**paths;

// 	i = 0;
// 	tmp = get_value_env(env, "PATH");
// 	paths = ft_split(tmp, ':');
// 	if (!paths)
// 		return (NULL);
// 	return (paths);
// }

int	check_end_path(char *path)
{
	if (path[ft_strlen(path) - 1] == '/')
		return (0);
	return (-1);
}

int	is_directory(char *cmd)
{
	int	fd;

	fd = open(cmd, O_DIRECTORY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

int	is_whitespace(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] == ' ' || (cmd[i] > 8 && cmd[i] < 14))
		i++;
	if (i == (int)ft_strlen(cmd))
		return (0);
	else
		return (-1);
}
