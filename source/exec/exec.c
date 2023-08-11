/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:48:55 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/10 16:36:18 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
Sort fd propre.
Si on impose un outfile ou un infile, on ouvre quand meme le pipe et on les met dan fd[4] pour le infile et fd[5] pour le outfile.
Si on est sur le dernier pipe, on ne doit pas ouvrir de nouveau pipe, la sortie se fera sur la sortie standard si aucun outfile n'est precise.
*/
int	set_pipe(t_datalist *list, int *fd)
{	
	fd[0] = fd[2];
	fd[1] = fd[3];
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
	if(list->infile)
		dup2(list->infile, STDIN_FILENO);
	else
		dup2(fd[0], STDIN_FILENO);

	if (list->outfile)
		dup2(list->outfile, STDOUT_FILENO);
	else
		dup2(fd[3], STDOUT_FILENO);
	close_fd(fd, 4);
	return (0);
}

/*
Exec une commande qui est un builtin.
*/
void	exec_builtin(t_datalist *datalist, t_env **envlst, int builtin)
{
	const t_builtins tab_builtins[] = {&cd_b, &echo_b, &env_b, &exit_b, &export_b, &pwd_b, &unset_b};
	
	(*tab_builtins[builtin])(datalist, envlst);
}

/*
Execute une fork qui correspond donc a un pipe.
Dans le cas ou l'exec ne fonctionne pas, exit avec un perror, il faudra check que le perror renvoie bien les bons trucs.
*/
int	exec_onepipe(t_datalist *datalist, int *fd, t_env **envlst)
{	
	char	*cmdwpath;
	char	**env;
	int		builtin;
	
	set_dup(datalist, fd);
	builtin = isbuiltin(datalist->cmd);
	if (builtin > -1)
		exec_builtin(datalist, envlst, builtin);
	else
	{
		env = env_to_tab(*envlst); // A free, ca malloc
		cmdwpath = check_cmd(env, datalist->cmd); // A free
		execve(cmdwpath, datalist->args, env);
	}
	return(0);
}

/*
Fonction a appeler dans le main.
Les heredocs sont executes dans init_struct.
*/
int	exec(t_big_list *list, t_env **envlst)
{
	int			i;
	int			fd[4];
	t_datalist	*datalist;

	// (void)envlst;

	datalist = init_struct(list);
	// print_datalist(datalist);
	i = 0;
	while (datalist)
	{
		if (set_pipe(datalist, fd) < 0)
			return (/*Free datalist*/-1);
		datalist->pid = fork();
		if (datalist->pid == 0)
			exec_onepipe(datalist, fd, envlst);
		i++;
		datalist = datalist->next;
	}
	while (i--)
		waitpid(-1, 0, 0);
	return (0);
}


// Faire un main pour tester !!!
