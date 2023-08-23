/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:57:32 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/23 16:33:34 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "minishell.h"

enum	e_errors
{
	nofile		=	0,
	isdir		=	1,
	notdir		=	2,
	cmd			=	3,
	perm		=	4,
	syntax		=	5,
	identifier	=	6,
	nbargs		=	7
};

typedef int	(*t_errors)(char *arg);

int	error_manager(char *str, int error_id);
int	error_nofile(char *str);
int	error_isdir(char *str);
int	error_notdir(char *str);
int	error_cmd(char *str);
int	error_perm(char *str);
int	error_syntax(char *str);
int	error_identifier(char *str);
int	error_args(char *str);

#endif
