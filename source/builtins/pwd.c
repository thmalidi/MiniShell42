/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:04:28 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/30 12:53:54 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_b(t_datalist *data, t_env **env)
{
	char	*pwd;

	(void)env;
	if (len_tab(data->args) > 2)
	{
		error_manager("pwd", NBARGS);
		return (-1);
	}
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (ft_dprintf(2, "getcwd failed\n"), -1);
	printf("%s\n", pwd);
	return (free(pwd), g_return_value);
}
