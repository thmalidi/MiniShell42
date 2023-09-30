/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:05:34 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/30 06:50:02 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_path(char **env);
static char	*lfcmd(char **paths, char *cmd);
static char	*check_cmd_nopath(char **paths, char *cmd);

static char	**get_path(char **env)
{
	int		i;
	char	**new_paths;
	char	**paths;

	paths = is_path(env);
	if (!paths)
		return (error_manager("get_path", MALLOC), NULL);
	new_paths = (char **)malloc(sizeof(char *) * (len_tab(paths) + 1));
	if (!new_paths)
		return (error_manager("get_path", MALLOC), free_tab(paths), NULL);
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
		{
			new_paths[i] = ft_strdup(paths[i]);
			if (!new_paths[i])
				return (error_manager("get_path", MALLOC), \
					free_tab(paths), free_tab(new_paths), NULL);
		}
	}
	new_paths[i] = NULL;
	return (free_tab(paths), new_paths);
}

static char	*lfcmd(char **paths, char *cmd)
{
	char	*cmd_to_check;
	int		i;

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
	return (cmd_to_check);
}

static char	*check_cmd_nopath(char **paths, char *cmd)
{
	char	*cmd_to_check;

	if (!paths || !paths[0])
		return (error_manager(cmd, CMD), NULL);
	if (is_whitespace(cmd) == YES)
		return (NULL);
	cmd_to_check = lfcmd(paths, cmd);
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
	char	**paths;
	char	*cmd_to_ret;
	int		fd;

	if (!cmd)
		return (NULL);
	if (is_acmd(cmd) == YES)
	{
		paths = get_path(env);
		if (!paths)
			return (error_manager(cmd, NOPATH), NULL);
		cmd_to_ret = check_cmd_nopath(paths, cmd);
		return (free_tab(paths), cmd_to_ret);
	}
	else
	{
		fd = open(cmd, O_DIRECTORY);
		if (fd > -1)
			return (close(fd), error_manager(cmd, ISDIR), NULL);
		if (access(cmd, F_OK) != 0)
			return (error_manager(cmd, NOPATH), NULL);
		else if (access(cmd, F_OK) == 0 && access(cmd, X_OK) != 0)
			return (error_manager(cmd, PERM), NULL);
		return (cmd);
	}
}
