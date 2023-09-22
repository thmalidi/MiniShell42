/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:25:04 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/22 08:58:35 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Set les valeurs de infile et outfile et 
supprimme de pipelist les elements correspondants.
Attention si la commande commence par une redir 
il faut ptet changer des trucs ici, reinit le pointeur.
*/
int	set_files(t_datalist *data, t_element **pipe, t_env **env, t_big_list *list)
{
	t_element	*tmp;

	tmp = *pipe;
	while (tmp)
	{
		if (tmp->type == 2)
		{
			if (data->infile > 0)
				close (data->infile);
			data->infile = exec_hd(data, tmp, env, list);
			if (data->infile < 0 || g_return_value > 128)
				return (-1);
		}
		if (tmp->type < 5 && tmp->type > 0)
		{
			if (manage_files(&tmp, pipe, data) < 0)
				return (0); // J'avais mis -1 somehow pour un truc
		}
		else
			tmp = tmp->next;
	}
	return (0);
}

/*
Remplit lstargs, t_element ne contient plus que ce dont on a besoin ici.
*/
char	**set_args(t_element *pipelist)
{
	t_element	*tmp;
	char		**args;
	int			i;

	args = (char **)malloc(sizeof(char *) * (element_len(pipelist) + 1));
	if (!args)
		return (NULL);
	tmp = pipelist;
	i = 0;
	while (tmp)
	{
		args[i] = ft_strdup(tmp->str);
		if (!args[i])
			return (free_tab(args), NULL);
		tmp = tmp->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}

/*
Initialise les data d'un element de la liste.
*/
int	init_data(t_datalist *datalist, t_datalist *full_data, t_big_list *list, t_env **env)
{
	t_element	*tmp;

	if (full_data)
		datalist->head = full_data;
	else
		datalist->head = datalist;
	tmp = *(list->pipelist);
	if (set_files(datalist, list->pipelist, env, list) < 0)
		return (-1);
	tmp = *(list->pipelist);
	if (tmp)
		datalist->cmd = ft_strdup(tmp->str);
	if (!datalist->cmd)
		return (0);
	datalist->args = set_args(*(list->pipelist));
	if (!(datalist->args))
		return (-1);
	return (0);
}

/*
Ajoute un element a la structure datalist et le remplit.
*/
int	fill_data(t_datalist **datalist, t_big_list *list, t_env **env)
{
	t_datalist	*new;
	t_datalist	*tmp;

	new = (t_datalist *)ft_calloc(1, sizeof(t_datalist));
	if (!new)
		return (-1);
	new->next = NULL;
	if (init_data(new, *datalist, list, env) < 0)
		return (free(new), -1);
	tmp = *datalist;
	if (!tmp)
	{
		*datalist = new;
		return (0);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

/*
Initialise la structure, on va exec les heredoc dedans, et set les fd.
Free la big_list.
*/
t_datalist	*init_struct(t_big_list *list, t_env **env)
{
	t_datalist	*datalist;
	t_big_list	*tmp;

	datalist = NULL;
	tmp = list;
	while (tmp)
	{
		if (fill_data(&datalist, tmp, env) < 0)
		{
			free_datalist(datalist);
			free_big_list(list);
			return (NULL);
		}
		tmp = tmp->next;
	}
	free_big_list(list);
	return (datalist);
}

// A del
// void	print_datalist(t_datalist *datalist)
// {
// 	t_datalist	*tmp;
// 	int			i;

// 	i = 0;
// 	tmp = datalist;
// 	while (tmp)
// 	{
// 		printf("\nDatalist du pipe %d :\n", i);
// 		printf("Cmd : %s\n", tmp->cmd);
// 		printf("fd du infile : %d\n", tmp->infile);
// 		printf("fd du outfile : %d\n", tmp->outfile);
// 		printf("Les arguments : \n");
// 		print_tab(tmp->args);
// 		tmp = tmp->next;
// 		i++;
// 		printf("\n");
// 	}
// }
