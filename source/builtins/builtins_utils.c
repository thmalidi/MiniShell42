/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:11:25 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/28 14:35:24 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Retourne -1 si ce n'est pas une var qu'on peut mettre dans l'env, 0 sinon.
*/
int	check_var(char *var, char *func)
{
	int	i;

	if (!var)
		return (-1);
	if (ft_isalpha((int)var[0]) == 0 && var[0] != '_' && var[0] != '\6')
		return (error_manager(func, IDENTIFIER), -1);
	i = 0;
	while (var[++i])
	{
		if (ft_isalnum((int)var[i]) == 0 && var[i] != '_')
			return (error_manager(func, IDENTIFIER), -1);
	}
	return (0);
}

int	is_option(char *str)
{
	if (str[0] == '-')
	{
		if (str[1])
			return (YES);
	}
	return (NO);
}

int	is_pwdoption(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
	{
		while (str[++i])
		{
			if (str[i] != '-')
				return (YES);
		}
	}
	return (NO);
}
/*
Func vaut 1 pour PWD, 0 sinon.
*/

int	is_an_option(char **tab, int func)
{
	int	i;

	i = -1;
	if (func == 0)
	{
		while (tab[++i])
		{
			if (is_option(tab[i]) == YES)
				return (YES);
		}
	}
	else
	{
		while (tab[++i])
		{
			if (is_pwdoption(tab[i]) == YES)
				return (YES);
		}
	}
	return (NO);
}

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
