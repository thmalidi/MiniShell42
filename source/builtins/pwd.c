/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:04:28 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/31 13:19:16 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_option(char *str)
{
	int	i;
	
	if (str[0] == '-')
	{
		i = 0;
		while (str[++i])
		{
			if (str[i] != '-')
				return (YES);
		}
	}
	return (NO);
}

int	is_an_option(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (is_option(tab[i]) == YES)
			return (YES);
	}
	return (NO);
}

int	pwd_b(t_datalist *data, t_env **env)
{
	char	*pwd;

	(void)env;
	if (is_an_option(data->args) == YES)
		return (error_manager("pwd", OPTION));
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (ft_dprintf(2, "getcwd failed\n"), -1);
	printf("%s\n", pwd);
	return (free(pwd), 0);
}
