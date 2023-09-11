/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:04:28 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/11 14:23:03 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	pwd_b(t_datalist *data, t_env **env)
{
	char	*pwd;

	(void)env;
	if (is_an_option(data->args, 1) == YES)
		return (error_manager("pwd", OPTION));
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (ft_dprintf(2, "getcwd failed\n"), -1);
	printf("%s\n", pwd);
	return (free(pwd), 0);
}
