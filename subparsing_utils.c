/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subparsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:15:36 by tmalidi           #+#    #+#             */
/*   Updated: 2023/07/16 11:12:00 by tmalidi          ###   ########.fr       */
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
			return (free(tmp), 1);
		free(joined);
		path++;
	}
	return (free(tmp), 0);
}

int    subparsing(t_element **subparsing)
{
    int i;
	t_element *tmp;
	t_element *first;
	char **envp;

    i = 0;
	first = *subparsing;
	tmp = *subparsing;
	envp = ft_split(getenv("PATH"), ':');
    while (tmp)
    {
        if (!ft_strncmp("<",tmp->str, ft_strlen(tmp->str)))
            tmp->type = 3;
        else if (!strncmp(">",tmp->str, ft_strlen(tmp->str)) && i == 1)
            tmp->type = 4;
		else if ((i == 0 || (tmp->next == NULL && first->type == 3)) && is_cmd(envp, tmp->str))
			tmp->type = 2;
		else if (tmp->previous)
		{
        	if ((tmp->previous->type == 3 || tmp->previous->type == 4 || tmp->previous->type == 2) && !access(tmp->str, F_OK))
				tmp->type = 1;
		}
		else
		{
			tmp->type = -1;
			return (free_tab(envp), 0);
		}
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