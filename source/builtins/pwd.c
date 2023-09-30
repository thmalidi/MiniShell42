/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:27:54 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/28 15:53:36 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_b(t_data *data)
{
	char	*pwd;

	g_return_value = 0;
	if (is_an_option(data->args, 1) == YES)
		return (error_manager("pwd", OPTION));
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		free(pwd);
		return (ft_dprintf(2, "cd: error retrieving current directory: \
getcwd: cannot access parent directories: No such file or directory\n"), \
		g_return_value);
	}
	printf("%s\n", pwd);
	return (free(pwd), g_return_value);
}
