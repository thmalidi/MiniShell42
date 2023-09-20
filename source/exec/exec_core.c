/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:39:46 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/20 14:34:03 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
Sort fd propre.
Si on impose un outfile ou un infile, on ouvre quand meme le pipe 
et on les met dan fd[4] pour le infile et fd[5] pour le outfile.
Si on est sur le dernier pipe, on ne doit pas ouvrir de nouveau pipe, 
la sortie se fera sur la sortie standard si aucun outfile n'est precise.
*/
int	set_pipe(t_datalist *list, int *fd)
{
	close_fd(fd, 2);
	fd[0] = fd[2];
	fd[1] = fd[3];
	fd[2] = 0;
	fd[3] = 0;
	if (list->next)
	{
		if (pipe(&fd[2]) < 0)
			return (-1);
	}
	return (0);
}

/*
Set le dup d'entree et de sortie.
On ne doit dup que si le fd est != de 0.
On doit prioriser les infile et outfile aux pipes.
*/
int	set_dup(t_datalist *list, int *fd, t_datalist *full_data)
{
	if (list->infile > 0)
		dup2(list->infile, STDIN_FILENO);
	else if (fd[0] > 0)
		dup2(fd[0], STDIN_FILENO);
	if (list->outfile > 0)
		dup2(list->outfile, STDOUT_FILENO);
	else if (fd[3] > 0)
		dup2(fd[3], STDOUT_FILENO);
	close_fd(fd, 4);
	close_datafd(full_data);
	return (0);
}

/*
Exec une commande qui est un builtin.
*/
void	exec_builtin(t_datalist *datalist, t_env **envlst, int builtin)
{
	const t_builtins	tab_builtins[] = {&cd_b, &echo_b, &env_b, \
										&exit_b, &export_b, &pwd_b, &unset_b};

	(*tab_builtins[builtin])(datalist, envlst);
}

int	exec_nobuiltin(t_datalist *data, t_env **envlst, t_datalist *full_data)
{
	char	*cmdwpath;
	char	**env;

	signal(SIGQUIT, &child_handler);
	env = env_to_tab(*envlst);
	free_env(*envlst);
	if (!env)
	{
		error_manager(data->cmd, CMD);
		exit (g_return_value);
	}
	cmdwpath = check_cmd(env, data->cmd);
	if (!cmdwpath)
	{
		free_tab(env);
		free_datalist(full_data);
		exit (g_return_value);
	}
	if (cmdwpath)
		execve(cmdwpath, data->args, env);
	free(cmdwpath);
	free_tab(env);
	free_datalist(full_data);
	exit (g_return_value);
}

/*
Retourne 0 si pas besoin de fork, 1 sinon
*/
int	need_to_fork(t_datalist *datalist, int builtin)
{
	if (builtin < 0)
		return (1);
	if (len_datalist(datalist) == 1)
	{
		if ((builtin == EXPORT && !(datalist->args)[1]) || builtin == ECHO \
			|| builtin == PWD || builtin == ENV)
			return (1);
		else
			return (0);
	}
	else
		return (1);
}
