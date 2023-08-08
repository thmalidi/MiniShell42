/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:25:04 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/08 13:59:16 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_file(char *file, int type, t_datalist *datalist)
{
	int	fd;
	
	fd = open(file, O_DIRECTORY, 0644);
	if (fd != -1)
	{
		printf("%s: is a directory\n", file);
		return (close(fd), -1);
	}
	if (type == 1)
	{
		if (datalist->infile)
			close(datalist->infile);
		datalist->infile = open(file, O_RDONLY, 0644);
		if (fd < 0)
			return (-1); //Print des trucs probablement
	}
	else if (type == 3)
	{
		if (datalist->outfile)
			close(datalist->outfile);
		datalist->outfile = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd < 0)
			return (-1); //Print des trucs probablement
	}
	else if (type == 4)
	{
		if (datalist->outfile)
			close(datalist->outfile);
		datalist->outfile = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (fd < 0)
			return (-1); //Print des trucs probablement
	}
	return (fd);
}

/*
Set les valeurs de infile et outfile et supprimme de pipelist les elements correspondants.
Attention si la commande commence par une redir il faut ptet changer des trucs ici, reinit le pointeur 
*/
int	set_files(t_datalist *datalist, t_element **pipelist)
{
	t_element	*tmp;

	tmp = *pipelist;
	while (tmp)
	{
		if (tmp->type < 3 && tmp->type > 0)
		{
			if(tmp->type == 1)
				check_file(tmp->next->str, tmp->type, datalist);
			else
				datalist->infile = exec_hd(tmp);
			if (!tmp->previous && tmp->next->next)
				tmp->next->next->previous = NULL; // Si c'est au debut de la chaine
			tmp = remove_files(tmp);
			if (!tmp || !(tmp->previous))
				*pipelist = tmp;
		}
		else if (tmp->type < 5 && tmp->type > 2)
		{
			check_file(tmp->next->str, tmp->type, datalist);
			if (!tmp->previous && tmp->next->next) // Si c'est au debut de la chaine
				tmp->next->next->previous = NULL;
			tmp = remove_files(tmp);
			if (!tmp || !(tmp->previous))
				*pipelist = tmp;
		}
		else
			tmp = tmp->next;
	}
	// printf("Pipelist fin de set_files : %s\n", (*(pipelist))->str);
	return (0);
}

/*
Remplit lstargs, t_element ne contient plus que ce dont on a besoin ici.
*/
char 	**set_args(t_element *pipelist)
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
			return(/*Free*/NULL);
		tmp = tmp->next;
		i++;
	}
	args[i] = NULL;
	return(args);
}

/*
Initialise les data d'un element de la liste.
*/
int	init_data(t_datalist *datalist, t_big_list *list)
{
	t_element	*tmp;

	tmp = *(list->pipelist);
	// while (tmp)
	// {
	// 	close_fd_hd(datalist->fd_hd);
	// 	if ()
	// 		datalist->fd_hd = exec_hd(tmp);
	// 	if (!datalist->fd_hd)
	// 		return(-1);
	// 	tmp = tmp->next;
	// }
	if (set_files(datalist, list->pipelist) != 0)
		return (-1);
	tmp = *(list->pipelist);
	if (tmp)
		datalist->cmd = ft_strdup(tmp->str);
	if (!datalist->cmd)
		return (-1);
	datalist->args = set_args(*(list->pipelist));
	if (!(datalist->args))
		return (/*Free le strdup ?*/-1);
	return (0);
}

/*
Ajoute un element a la structure datalist et le remplit.
*/
int	fill_data(t_datalist **datalist, t_big_list *list)
{
	t_datalist *new;
	t_datalist *tmp;

	new = (t_datalist *)ft_calloc(1, sizeof(t_datalist)); // Calloc...
	if (!new)
		return (-1);
	new->next = NULL;
	if (init_data(new, list) != 0)
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
t_datalist	*init_struct(t_big_list *list)
{
	t_datalist	*datalist;
	t_big_list	*tmp;

	datalist = NULL;
	tmp = list;
	while (tmp)
	{
		if (fill_data(&datalist, tmp) < 0)
			return (free_big_list(list), NULL);
		tmp = tmp->next;
	}
	free_big_list(list);
	return (datalist);
}

void	print_datalist(t_datalist *datalist)
{
	t_datalist	*tmp;
	int			i;

	i = 0;
	tmp = datalist;
	while (tmp)
	{
		printf("\nDatalist du pipe %d :\n", i);
		printf("Cmd : %s\n", tmp->cmd);
		printf("fd du infile : %d\n", datalist->infile);
		printf("Premiere ligne du infile : %s\n", get_next_line(tmp->infile));
		printf("fd du outfile : %d\n", datalist->outfile);
		printf("Premiere ligne du outfile : %s\n", get_next_line(tmp->outfile));
		printf("Les arguments : \n");
		print_tab(tmp->args);
		tmp = tmp->next;
		i++;
		printf("\n");
	}
}
