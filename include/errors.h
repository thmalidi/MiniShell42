/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:57:32 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/21 11:46:20 by hgeffroy         ###   ########.fr       */
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
	MALLOC		=	8,
	OPTION		=	9,
	QUOTES		=	10,
	HD			=	11,
	NOTSET		=	12
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
int	error_option(char *str);
int	error_quotes(char *str);
int	error_hd(char *str);
int	error_notset(char *str);

#endif
