/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:46:08 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/22 09:48:34 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_infile(char *file, t_data *datalist)
{
	if (datalist->infile > 0)
	{
		close(datalist->infile);
		datalist->infile = 0;
	}
	if (access(file, F_OK) < 0)
	{
		datalist->infile = -1;
		if (datalist->outfile > 0)
			close(datalist->outfile);
		return (error_manager(file, NOFILE), -1);
	}
	else if (access(file, R_OK) < 0)
	{
		if (datalist->outfile > 0)
			close(datalist->outfile);
		return (error_manager(file, PERM), -1);
	}
	datalist->infile = open(file, O_RDONLY, 0644);
	return (0);
}

int	check_outfile(char *file, t_data *datalist)
{
	if (datalist->outfile > 0)
	{
		close(datalist->outfile);
		datalist->outfile = 0;
	}
	if (access(file, F_OK) == 0 && access(file, W_OK) < 0)
	{
		datalist->outfile = -1;
		if (datalist->infile > 0)
			close(datalist->infile);
		return (error_manager(file, PERM), -1);
	}
	datalist->outfile = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (0);
}

int	check_appfile(char *file, t_data *datalist)
{
	if (datalist->outfile > 0)
	{
		close(datalist->outfile);
		datalist->outfile = 0;
	}
	if (access(file, F_OK) == 0 && access(file, W_OK) < 0)
	{
		datalist->outfile = -1;
		if (datalist->infile > 0)
			close(datalist->infile);
		return (error_manager(file, PERM), -1);
	}
	datalist->outfile = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	return (0);
}

int	check_file(char *file, int type, t_data *datalist)
{
	int	fd;

	fd = open(file, O_DIRECTORY, 0644);
	if (fd != -1)
	{
		if (datalist->infile > 0)
			close(datalist->infile);
		if (datalist->outfile > 0)
			close(datalist->outfile);
		return (error_manager(file, ISDIR), close(fd), -1);
	}
	if (type == 1)
	{
		if (check_infile(file, datalist) < 0)
			return (-1);
	}
	else if (type == 3)
	{
		if (check_outfile(file, datalist) < 0)
			return (-1);
	}
	else if (type == 4)
	{
		if (check_appfile(file, datalist) < 0)
			return (-1);
	}
	return (0);
}

int	manage_files(t_element **tmp, t_element **pipelist, t_data *datalist)
{
	if (check_file((*tmp)->next->str, (*tmp)->type, datalist) < 0)
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
