/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:03:55 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/11 15:53:26 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
		{
			g_return_value = 1;
			ft_dprintf(2, "%s: No such file or directory\n", path);
			return (NO);
		}
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
	chdir(get_value_env(*env, "HOME"));
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
	chdir(get_value_env(*env, "OLDPWD"));
	set_value_env(env, "OLDPWD", dir);
	free(dir);
	dir = getcwd(NULL, 0);
	if (!dir)
		return (-1);
	set_value_env(env, "PWD", dir);
	return (0);
}

int	spec_manager(t_datalist *data, t_env **env)
{
	if (!(data->args[1]) || ft_strcmp(data->args[1], "~") == 0 \
		|| ft_strcmp(data->args[1], "~/") == 0)
	{
		go_root(env);
		return (1);
	}
	else if (ft_strcmp(data->args[1], "-") == 0)
	{
		go_back(env);
		return (1);
	}
	return (0);
}

int	cd_b(t_datalist *data, t_env **env)
{
	char	*dir;

	if (len_tab(data->args) > 2)
		return (error_manager("cd", NBARGS), -1);
	if (spec_manager(data, env) == 1)
		return (0);
	if (is_an_option(data->args, 0) == YES)
		return (error_manager("cd", OPTION), g_return_value);
	dir = getcwd(NULL, 0);
	if (!dir)
		return (-1);
	set_value_env(env, "OLDPWD", dir);
	free(dir);
	if (is_valid_dir(data->args[1]) == NO)
		return (-1);
	chdir(data->args[1]);
	dir = getcwd(NULL, 0);
	if (!dir)
		return (-1);
	set_value_env(env, "PWD", dir);
	free(dir);
	return (0);
}
