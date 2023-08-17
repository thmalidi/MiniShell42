/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:26:33 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/16 14:32:39 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*A refaire avec access et stat ?*/

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
				return (printf("Malloc failed in parsing\n"), \
					free_tab(paths), free_tab(new_paths), NULL);
		}
		else
			new_paths[i] = ft_strdup(paths[i]);
	}
	new_paths[i] = NULL;
	return (free_tab(paths), new_paths);
}

char	*check_cmd_nopath(char **paths, char *cmd, int i)
{
	char	*cmd_to_check;
	char	**cmd_splitted;

	if (is_whitespace(cmd) > 0)
		return (NULL);
	cmd_to_check = ft_strjoin(paths[i], cmd);
	if (!cmd_to_check)
	{
		printf("Malloc failed in parsing\n");
		return (free_tab(paths), NULL);
	}
	cmd_splitted = ft_split(cmd_to_check, ' ');
	if (!cmd_splitted)
	{
		printf("Malloc failed in parsing\n");
		return (free(cmd_to_check), free_tab(paths), NULL);
	}
	else if (access(cmd_splitted[0], X_OK) == 0)
		return (free_tab(paths), free_tab(cmd_splitted), cmd_to_check);
	free(cmd_to_check);
	free_tab(cmd_splitted);
	return (NULL);
}

char	*check_cmd_path(char *cmd)
{
	char	**cmd_splitted;

	cmd_splitted = ft_split(cmd, ' ');
	if (!cmd_splitted)
		return (NULL);
	if (is_cmdwpath(cmd_splitted[0]) < 0)
		return (free_tab(cmd_splitted), NULL);
	if (access(cmd_splitted[0], X_OK) == 0)
		return (free_tab(cmd_splitted), ft_strdup(cmd));
	free_tab(cmd_splitted);
	return (NULL);
}

char	*check_cmd(char **env, char *cmd)
{
	char	**paths;
	char	*cmd_to_check;
	int		i;

	if (is_directory(cmd) == 0)
		return (printf("%s: Is a directory\n", cmd), NULL);
	cmd_to_check = check_cmd_path(cmd);
	if (cmd_to_check)
		return (cmd_to_check);
	paths = get_path(env);
	if (!paths)
		return (printf("%s: No such file or directory\n", cmd), NULL);
	i = -1;
	while (paths[++i])
	{
		cmd_to_check = check_cmd_nopath(paths, cmd, i);
		if (cmd_to_check)
			return (cmd_to_check);
	}
	free_tab(paths);
	free(cmd_to_check);
	printf("Command not found: %s\n", cmd);
	return (NULL);
}


// #include <stddef.h>
// #include <stdlib.h>
// int main(int ac, char **av, char **env)
// {
// 	char **test;

// 	test = (char **)malloc(sizeof(char *) * 5);

// 	test[0] = strdup("/bin/ls");
// 	test[1] = strdup("exec.h");
// 	test[2] = strdup("a");
// 	test[3] = strdup("e");
// 	test[4] = NULL;
	
// 	execve(test[0], test, env);
// 	puts("\n");
// 	//perror("\n");
// 	return (0);
// }