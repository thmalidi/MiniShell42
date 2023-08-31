/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:10:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/31 14:42:19 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_infile(char *file, t_datalist *datalist)
{
	if (datalist->infile)
		close(datalist->infile);
	if (access(file, F_OK) < 0)
		return (error_manager(file, NOFILE), -1);
	else if (access(file, R_OK) < 0)
		return (error_manager(file, PERM), -1);
	datalist->infile = open(file, O_RDONLY, 0644);
	return (0);
}

int	check_outfile(char *file, t_datalist *datalist)
{
	if (datalist->infile)
		close(datalist->infile);
	if (access(file, F_OK) == 0 && access(file, W_OK) < 0)
		return (error_manager(file, PERM), -1);
	datalist->outfile = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (0);
}

int	check_appfile(char *file, t_datalist *datalist)
{
	if (datalist->infile)
		close(datalist->infile);
	if (access(file, F_OK) == 0 && access(file, W_OK) < 0)
		return (error_manager(file, PERM), -1);
	datalist->outfile = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	return (0);
}

int	check_file(char *file, int type, t_datalist *datalist)
{
	int	fd;

	fd = open(file, O_DIRECTORY, 0644);
	if (fd != -1)
		return (error_manager(file, ISDIR), close(fd), -1);
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
