/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:05:34 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/13 10:04:56 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

/*
On check d'abord si c'est une commande (pas de /) ou un file (avec /).
Si c'est une commande, recuperer le path et faire les trucs.
Sinon, check si le file existe, puis les perms.
*/

int	is_acmd(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '/')
			return (NO);
	}
	return (YES);
}

char	**get_path(char **env)
{
	int		i;
	char	**new_paths;
	char	**paths;

	paths = is_path(env);
	if (!paths)
		return (NULL);
	new_paths = (char **)malloc(sizeof(char *) * (len_tab(paths) + 1));
	if (!new_paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		if (check_end_path(paths[i]) < 0)
		{
			new_paths[i] = ft_strjoin(paths[i], "/");
			if (!new_paths[i])
				return (error_manager("get_path", MALLOC), \
					free_tab(paths), free_tab(new_paths), NULL);
		}
		else
			new_paths[i] = ft_strdup(paths[i]);
	}
	new_paths[i] = NULL;
	return (free_tab(paths), new_paths);
}

char	*check_cmd_nopath(char **paths, char *cmd)
{
	char	*cmd_to_check;
	int		i;

	if (!paths || !paths[0])
		return (error_manager(cmd, CMD), NULL);
	if (is_whitespace(cmd) == 0)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		cmd_to_check = ft_strjoin(paths[i], cmd);
		if (!cmd_to_check)
		{
			error_manager("check_cmd_nopath", MALLOC);
			return (free(cmd_to_check), NULL);
		}
		if (access(cmd_to_check, F_OK) == 0)
			break ;
		free(cmd_to_check);
		cmd_to_check = NULL;
	}
	if (!cmd_to_check)
		error_manager(cmd, CMD);
	else if (access(cmd_to_check, X_OK) == 1)
	{
		error_manager(cmd, PERM);
		return (free(cmd_to_check), NULL);
	}
	return (cmd_to_check);
}

char	*check_cmd(char **env, char *cmd)
{
	if (!cmd)
		return (NULL);
	if (is_acmd(cmd) == YES)
		return (check_cmd_nopath(get_path(env), cmd));
	else
	{
		if (open(cmd, O_DIRECTORY) > -1)
			return (error_manager(cmd, ISDIR), NULL);
		if (access(cmd, F_OK) != 0)
			return (error_manager(cmd, NOFILE), NULL);
		else if (access(cmd, F_OK) == 0 && access(cmd, X_OK) != 0)
			return (error_manager(cmd, PERM), NULL);
		return (cmd);
	}
}
