/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:36:32 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/21 14:13:36 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include "exec.h"
# include "env.h"

enum	e_builtin
{
	CD		=	0,
	ECHO	=	1,
	ENV		=	2,
	EXIT	=	3,
	EXPORT	=	4,
	PWD		=	5,
	UNSET	=	6
};

// Utils
char	**parsing_export(char *arg);
char	**ft_split_export(char *arg);
int		check_var(char *var, char *func);
int		is_an_option(char **tab, int func);

// Fct builtins
int		cd_b(t_datalist *data, t_datalist *f_data, t_env **env);
int		echo_b(t_datalist *data, t_datalist *f_data, t_env **env);
int		env_b(t_datalist *data, t_datalist *f_data, t_env **env);
int		exit_b(t_datalist *data, t_datalist *f_data, t_env **env);
int		export_b(t_datalist *data, t_datalist *f_data, t_env **env);
int		pwd_b(t_datalist *data, t_datalist *f_data, t_env **env);
int		unset_b(t_datalist *data, t_datalist *f_data, t_env **env);

#endif