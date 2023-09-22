/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:46:08 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/22 10:00:32 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_infile(char *file, t_data *data)
{
	if (data->infile > 0)
	{
		close(data->infile);
		data->infile = 0;
	}
	if (access(file, F_OK) < 0)
	{
		data->infile = -1;
		if (data->outfile > 0)
			close(data->outfile);
		return (error_manager(file, NOFILE), -1);
	}
	else if (access(file, R_OK) < 0)
	{
		if (data->outfile > 0)
			close(data->outfile);
		return (error_manager(file, PERM), -1);
	}
	data->infile = open(file, O_RDONLY, 0644);
	return (0);
}

int	check_outfile(char *file, t_data *data)
{
	if (data->outfile > 0)
	{
		close(data->outfile);
		data->outfile = 0;
	}
	if (access(file, F_OK) == 0 && access(file, W_OK) < 0)
	{
		data->outfile = -1;
		if (data->infile > 0)
			close(data->infile);
		return (error_manager(file, PERM), -1);
	}
	data->outfile = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (0);
}

int	check_appfile(char *file, t_data *data)
{
	if (data->outfile > 0)
	{
		close(data->outfile);
		data->outfile = 0;
	}
	if (access(file, F_OK) == 0 && access(file, W_OK) < 0)
	{
		data->outfile = -1;
		if (data->infile > 0)
			close(data->infile);
		return (error_manager(file, PERM), -1);
	}
	data->outfile = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	return (0);
}

int	check_file(char *file, int type, t_data *data)
{
	int	fd;

	fd = open(file, O_DIRECTORY, 0644);
	if (fd != -1)
	{
		if (data->infile > 0)
			close(data->infile);
		if (data->outfile > 0)
			close(data->outfile);
		return (error_manager(file, ISDIR), close(fd), -1);
	}
	if (type == 1 && check_infile(file, data) < 0)
		return (-1);
	else if (type == 3 && check_outfile(file, data) < 0)
		return (-1);
	else if (type == 4 && check_appfile(file, data) < 0)
		return (-1);
	return (0);
}

int	manage_files(t_element **tmp, t_element **pipelist, t_data *data)
{
	if (check_file((*tmp)->next->str, (*tmp)->type, data) < 0)
	{
		*tmp = remove_files(*tmp);
		if (!(*tmp) || !((*tmp)->previous))
			*pipelist = *tmp;
		return (-1);
	}
	*tmp = remove_files(*tmp);
	if (!(*tmp) || !((*tmp)->previous))
		*pipelist = *tmp;
	return (0);
}
