/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:03:55 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/23 15:39:00 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Si plusieurs arguments, n'execute que le premier !!
Gerer cd - ? (Envoit a la racine)
Il faut parser ce bordel un peu !
*/



int	cd_b(t_datalist *data, t_env **env)
{
	char	*dir;

	if (!(data->args[1]))
		return (-1);
	dir = getcwd(NULL, 0);
	if (!dir)
		return (-1);
	set_value_env(env, "OLDPWD", dir);
	free(dir);
	chdir(data->args[1]);
	if (!dir)
		return (-1);
	dir = getcwd(NULL, 0);
	set_value_env(env, "PWD", dir);
	free(dir);
	return (0);
}

// Il faut tester les acces aux dossiers ?