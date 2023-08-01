/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subparsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:15:36 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/01 16:42:28 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*joined;

	if (!path)
		return (0);
	if (access(cmd, X_OK) == 0)
		return (1);
	tmp = ft_strjoin("/", cmd);
	while (*path)
	{
		joined = ft_strjoin(*path, tmp);
		if (access(joined, X_OK) == 0)
			return (free(tmp), free(joined), 1);
		free(joined);
		path++;
	}
	return (free(tmp), 0);
}

int is_builtins(char *str)
{
	if (!ft_strncmp("echo",str, ft_strlen(str)))
		return (1);
	if (!ft_strncmp("cd",str, ft_strlen(str)))
		return (1);
	if (!ft_strncmp("pwd",str, ft_strlen(str)))
		return (1);
	if (!ft_strncmp("unset",str, ft_strlen(str)))
		return (1);
	if (!ft_strncmp("env",str, ft_strlen(str)))
		return (1);
	if (!ft_strncmp("export",str, ft_strlen(str)))
		return (1);
	if (!ft_strncmp("exit",str, ft_strlen(str)))
		return (1);
	return (0);
}

int    subparsing(t_element **subparsing, t_big_list *arg)
{
    int i;
	t_element *tmp;
	//t_element *first;
	char **envp;

    i = 0;
	arg->here_doc = 0;
	tmp = *subparsing;
	envp = ft_split(getenv("PATH"), ':');
    while (tmp)
    {
		printf("tmp[0] == %c\n",tmp->str[0]);
        if (!ft_strncmp("<",tmp->str, ft_strlen(tmp->str)))																	//infile
            tmp->type = 1;
		else if (!ft_strncmp("<<",tmp->str, ft_strlen(tmp->str)))
		{
			arg->here_doc = 1;
			tmp->type = 2;
		}
        else if (!strncmp(">",tmp->str, ft_strlen(tmp->str)))																//outfile
            tmp->type = 3;
		else if (!strncmp(">>",tmp->str, ft_strlen(tmp->str)))
            tmp->type = 4;
		else if(tmp->str[0] == '-')																							//flag
			tmp->type = 5;
		else if (!access(tmp->str, F_OK))																					//fichier
			tmp->type = 6;
		else if (is_builtins(tmp->str))																						//builtins
			tmp->type = 7;
		else if (is_cmd(envp, tmp->str))																					//commande
			tmp->type = 8;
		else
			tmp->type = -1;
		tmp = tmp->next;
        i++;
    }
    return (free_tab(envp), 1);
}

/*int main()
{
	char **envp = ft_split(getenv("PATH"), ':');
	
	printf("<<<<<<<<<<<<<<<<<<<<<<<<%d",is_cmd(envp, "ls"));
}*/