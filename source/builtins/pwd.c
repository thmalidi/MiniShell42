/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:27:54 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/21 14:16:27 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_b(t_datalist *data, t_datalist *f_data, t_env **env)
{
	char	*pwd;

	(void)env;
	(void)f_data;
	g_return_value = 0;
	if (is_an_option(data->args, 1) == YES)
		return (error_manager("pwd", OPTION));
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		return (ft_dprintf(2, "cd: error retrieving current directory: \
getcwd: cannot access parent directories: No such file or directory\n"), \
		g_return_value);
	}
	printf("%s\n", pwd);
	return (free(pwd), g_return_value);
}
