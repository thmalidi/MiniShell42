/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:03:55 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/24 15:47:25 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Si plusieurs arguments, n'execute que le premier !!
Si pas d'arguments, renvoit a la racine aussi.
Gerer cd - ? (Envoit a la racine).
Il faut parser ce bordel un peu !
*/

/*
Fonction qui renvoit YES si c'est un directory ACCESSIBLE, NO sinon.
La gestion d'erreur y est faite.
*/
int	is_valid_dir(char *path)
{
	struct stat	sb;

	if (stat(path, &sb) == -1)
	{
		if (errno == EACCES)
			return (error_manager(path, PERM), NO);
		else
			return (error_manager(path, NOFILE), NO);
	}
	if (S_ISREG(sb.st_mode))
		return (error_manager(path, NOTDIR), NO);
	return (YES);
}

int	go_root(t_env **env)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	if (!dir)
		return (-1);
	set_value_env(env, "OLDPWD", dir);
	free(dir);
	chdir("/Users/henri"); // A changer en fonction de la session de correction
	dir = getcwd(NULL, 0);
	if (!dir)
		return (-1);
	set_value_env(env, "PWD", dir);
	return (0);
}

int	go_back(t_env **env)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	if (!dir)
		return (-1);
	chdir(get_value_env(*env, "OLDPWD")); // A changer en fonction de la session de correction
	set_value_env(env, "OLDPWD", dir);
	free(dir);
	dir = getcwd(NULL, 0);
	if (!dir)
		return (-1);
	set_value_env(env, "PWD", dir);
	return (0);
}

int	cd_b(t_datalist *data, t_env **env)
{
	char	*dir;

	if (!(data->args[1]) || ft_strcmp(data->args[1], "~") == 0)
	{
		go_root(env);
		return (return_value);
	}
	if (ft_strcmp(data->args[1], "-") == 0)
	{
		go_back(env);
		return (return_value);
	}
	dir = getcwd(NULL, 0);
	if (!dir)
		return (-1);
	set_value_env(env, "OLDPWD", dir);
	free(dir);
	if (is_valid_dir(data->args[1]) == NO)
		return (return_value);
	chdir(data->args[1]);
	dir = getcwd(NULL, 0);
	if (!dir)
		return (-1);
	set_value_env(env, "PWD", dir);
	free(dir);
	return (return_value);
}

// Il faut tester les acces aux dossiers ?