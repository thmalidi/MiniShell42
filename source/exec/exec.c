/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:48:55 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/12 11:36:21 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
int	set_dup(t_datalist *list, int *fd)
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

int	exec_nobuiltin(t_datalist *datalist, t_env **envlst)
{
	char	*cmdwpath;
	char	**env;

	signal(SIGQUIT, &child_handler);
	env = env_to_tab(*envlst);
	if (!env)
		exit (g_return_value);
	cmdwpath = check_cmd(env, datalist->cmd);
	if (!cmdwpath)
	{
		free_tab(env);
		exit (g_return_value);
	}
	execve(cmdwpath, datalist->args, env);
	free_tab(env);
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
	{
		if (builtin == CD || builtin == UNSET)
			return (0);
		else
			return (1);
	}
}

/*
Execute une fork qui correspond donc a un pipe.
Dans le cas ou l'exec ne fonctionne pas, exit avec un perror,
il faudra check que le perror renvoie bien les bons trucs.
*/
int	exec_onepipe(t_datalist *datalist, int *fd, t_env **envlst)
{	
	int		builtin;

	if (!(datalist->cmd))
		return (0);
	builtin = is_builtin(datalist->cmd);
	if (need_to_fork(datalist, builtin) == 0)
		exec_builtin(datalist, envlst, builtin);
	else
	{
		datalist->pid = fork();
		ignore_signals();
		if ((datalist->infile < 0 || datalist->outfile < 0) \
			&& datalist->pid == 0)
		{
			free_datalist(datalist);
			free_env(*envlst);
			exit (1);
		}
		if (datalist->pid == 0)
		{
			signal(SIGINT, &child_handler);
			set_dup(datalist, fd);
			if (builtin > -1)
			{
				exec_builtin(datalist, envlst, builtin);
				free_env(*envlst);
				free_datalist(datalist);
				exit (g_return_value);
			}
			else
				exec_nobuiltin(datalist, envlst);
			free_datalist(datalist);
			free_env(*envlst);
		}
	}
	return (0);
}

int	wait_processes(t_datalist *datalist)
{
	t_datalist	*tmp;
	int			status;

	tmp = datalist;
	status = 0;
	while (tmp)
	{
		if (tmp->pid && waitpid(tmp->pid, &status, WUNTRACED) == -1)
		{
			g_return_value = 1;
			return (-1);
		}
		else if (tmp->pid && WIFEXITED(status))
			g_return_value = WEXITSTATUS(status); // Je ne veux pas rentrer ici si on etait pas fork
		else if (WIFSIGNALED(status))
			child_handler(WTERMSIG(status));
		tmp = tmp->next;
		// Regarder comment recuperer la valeur de retour ici...
	}
	return (0);
}

/*
Fonction a appeler dans le main.
Les heredocs sont executes dans init_struct.
Mettre les conditions sur le fork.
*/
int	exec(t_big_list *list, t_env **envlst)
{
	int			fd[4];
	t_datalist	*datalist;
	t_datalist	*tmp;

	ft_bzero(fd, 4 * sizeof(int));
	datalist = init_struct(list);
	// print_datalist(datalist);
	if (!datalist)
		return (0);
	tmp = datalist;
	while (tmp)
	{
		if (set_pipe(tmp, fd) < 0)
			return (free_datalist(datalist), -1);
		if (exec_onepipe(tmp, fd, envlst))
			return (/*Close des trucs et free ?*/free_datalist(datalist), -1);
		if (tmp->infile)
			close(tmp->infile);
		if (tmp->outfile)
			close(tmp->outfile);
		close_fd(fd, 2);
		tmp = tmp->next;
	}
	wait_processes(datalist);
	free_datalist(datalist);
	return (0);
}

// Faire un main pour tester sans le main minishell !
