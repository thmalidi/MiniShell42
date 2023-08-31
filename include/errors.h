/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:57:32 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/30 16:04:57 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "minishell.h"

enum	e_errors
{
	NOFILE		=	0,
	ISDIR		=	1,
	NOTDIR		=	2,
	CMD			=	3,
	PERM		=	4,
	SYNTAX		=	5,
	IDENTIFIER	=	6,
	NBARGS		=	7,
	MALLOC		=	8
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
int	error_malloc(char *str);

#endif
