/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:03:55 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/10 09:15:34 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Si plusieurs arguments, n'execute que le premier !!
Changer de repertoire courant chdir
Mettre a jour pwd
Mettre a jour le old pwd
*/
int cd_b(t_datalist *data, t_env *env)
{
	char	*dir;

	if (!(data->args[1])) //On peut retourner a la racine au pire
		return (-1);
	dir = getcwd(NULL, 0);
	set_value_env(env, "OLDPWD", dir);
	chdir(data->args[1]);
	dir = getcwd(NULL, 0);
	set_value_env(env, "PWD", dir);
	return (0);
}

// Il faut tester les acces aux dossiers ?