/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:48:55 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/15 10:24:51 by hgeffroy         ###   ########.fr       */
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
	fd[0] = fd[2];
	fd[1] = fd[3];
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
	if (list->infile)
		dup2(list->infile, STDIN_FILENO);
	else if (fd[0])
		dup2(fd[0], STDIN_FILENO);
	if (list->outfile)
		dup2(list->outfile, STDOUT_FILENO);
	else if (fd[3])
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

	// fork ici si besoin (si pas exit)
	(*tab_builtins[builtin])(datalist, envlst);
	exit(0);
}

/*
Execute une fork qui correspond donc a un pipe.
Dans le cas ou l'exec ne fonctionne pas, exit avec un perror,
il faudra check que le perror renvoie bien les bons trucs.
*/
int	exec_onepipe(t_datalist *datalist, int *fd, t_env **envlst)
{	
	char	*cmdwpath;
	char	**env;
	int		builtin;

	datalist->pid = fork();
	if (datalist->pid == 0)
	{
		signal(SIGQUIT, &child_handler);
		set_dup(datalist, fd);
		builtin = is_builtin(datalist->cmd);
		if (builtin > -1)
			exec_builtin(datalist, envlst, builtin);
		else
		{
			// fork ici
			env = env_to_tab(*envlst); // A free, ca malloc + protection
			if (!env)
				return (-1);
			cmdwpath = check_cmd(env, datalist->cmd); // A free
			if (!cmdwpath)
				return (free_tab(env), -1);
			execve(cmdwpath, datalist->args, env);
		}
	}
	return (0);
}

/*
Ctrl-D marche plus depuis que j'ai fait ca...
*/
int	wait_processes(t_datalist *datalist)
{
	t_datalist	*tmp;
	int			status;

	tmp = datalist;
	status = 0;
	while (tmp)
	{
		if (tmp->pid)
			waitpid(tmp->pid, &status, WUNTRACED);
		if (WIFEXITED(status))
			/*Valeur de retour = WEXITSTATUS(status)*/;
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
	tmp = datalist;
	// print_datalist(datalist);
	while (tmp)
	{
		if (set_pipe(tmp, fd) < 0)
			return (free_datalist(datalist), -1);
		if (exec_onepipe(tmp, fd, envlst) < 0)
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
