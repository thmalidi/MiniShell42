/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:26:33 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/06 16:32:26 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Retourne les tableau que execve prendra en argument.
Retourne NULL si ce n'est pas une commande existante.
Attention probleme si 2 signes de redir a la suite !! A gerer au parsing ?
*/
char	**gen_args(t_datalist *data)
{
	// int			i;
	// t_lstargs	*tmp;
	// char		**args;

	// tmp = data->lstargs;
	// args = (char **)malloc(sizeof(char *) * (lstargs_len(tmp) + 2));
	// if (!args)
	// 	return (NULL);
	// args[0] = ft_strdup(data->cmd);
	// if (!args[0])
	// 	return(free(args), NULL);
	// i = 1;
	// while (tmp)
	// {
	// 	args[i] = tmp->arg;
	// 	i++;
	// 	tmp = tmp->next;
	// }
	// return (args);
	(void)data;
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