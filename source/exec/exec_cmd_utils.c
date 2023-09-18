/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:01:48 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/15 15:30:45 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

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

int	check_end_path(char *path)
{
	if (path[ft_strlen(path) - 1] == '/')
		return (0);
	return (-1);
}

int	is_whitespace(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] == ' ' || (cmd[i] > 8 && cmd[i] < 14))
		i++;
	if (i == (int)ft_strlen(cmd))
		return (YES);
	else
		return (NO);
}
