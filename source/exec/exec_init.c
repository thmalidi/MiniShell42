/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:25:04 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/23 15:56:29 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Set les valeurs de infile et outfile et 
supprimme de pipelist les elements correspondants.
Attention si la commande commence par une redir 
il faut ptet changer des trucs ici, reinit le pointeur.
*/
int	set_files(t_data *data, t_element **pipe, t_big_list *list)
{
	t_element	*tmp;

	tmp = *pipe;
	while (tmp)
	{
		if (tmp->type == 2)
		{
			if (data->infile > 0)
				close (data->infile);
			data->infile = exec_hd(data, tmp, list);
			if (data->infile < 0 || g_return_value > 128)
				return (-1);
		}
		if (tmp->type < 5 && tmp->type > 0)
		{
			if (tmp->next && ft_strcmp(tmp->next->str, "\0") == 0)
				error_manager("", AMBIGUOUS);
			if (manage_files(&tmp, pipe, data) < 0)
				return (0);
		}
		else
			tmp = tmp->next;
	}
	return (0);
}
// J'avais return -1 si manage_files < 0 somehow pour un truc

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
int	init_data(t_data *data, t_data *f_data, t_big_list *list, t_env **env)
{
	t_element	*tmp;

	if (f_data)
		data->head = f_data;
	else
		data->head = data;
	data->env = env;
	tmp = *(list->pipelist);
	if (set_files(data, list->pipelist, list) < 0)
		return (-1);
	tmp = *(list->pipelist);
	if (tmp)
		data->cmd = ft_strdup(tmp->str);
	if (!data->cmd)
		return (0);
	data->args = set_args(*(list->pipelist));
	if (!(data->args))
		return (-1);
	return (0);
}

/*
Ajoute un element a la structure data et le remplit.
*/
int	fill_data(t_data **data, t_big_list *list, t_env **env)
{
	t_data	*new;
	t_data	*tmp;

	new = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!new)
		return (-1);
	new->next = NULL;
	if (init_data(new, *data, list, env) < 0)
		return (free(new), -1);
	tmp = *data;
	if (!tmp)
	{
		*data = new;
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
t_data	*init_struct(t_big_list *list, t_env **env)
{
	t_data		*data;
	t_big_list	*tmp;

	data = NULL;
	tmp = list;
	while (tmp)
	{
		if (fill_data(&data, tmp, env) < 0)
		{
			free_data(data);
			free_big_list(list);
			return (NULL);
		}
		tmp = tmp->next;
	}
	free_big_list(list);
	return (data);
}

// A del
void	print_data(t_data *data)
{
	t_data		*tmp;
	int			i;

	i = 0;
	tmp = data;
	while (tmp)
	{
		printf("\nDatalist du pipe %d :\n", i);
		printf("Cmd : %s\n", tmp->cmd);
		printf("fd du infile : %d\n", tmp->infile);
		printf("fd du outfile : %d\n", tmp->outfile);
		printf("Les arguments : \n");
		print_tab(tmp->args);
		tmp = tmp->next;
		i++;
		printf("\n");
	}
}
