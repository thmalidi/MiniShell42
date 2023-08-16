/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:14:14 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/16 10:49:39 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include "exec.h"
# include "env.h"

// Utils
void	print_tab(char **tab);
int		len_tab(char **tab);
int		check_var(char *var);
char	**parsing_export(char *arg);
char	**ft_split_export(char *arg);
int		check_var(char *var);

// Fct builtins
int 	cd_b(t_datalist *data, t_env **env);
int 	echo_b(t_datalist *data, t_env **env);
int 	env_b(t_datalist *data, t_env **env);
int 	exit_b(t_datalist *data, t_env **env);
int 	export_b(t_datalist *data, t_env **env);
int 	pwd_b(t_datalist *data, t_env **env);
int 	unset_b(t_datalist *data, t_env **env);

#endif