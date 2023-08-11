/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:04:28 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/10 16:19:55 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_b(t_datalist *data, t_env **env)
{
	char	*pwd;

	(void)env;
	if (len_tab(data->args) > 2)
		printf("pwd shouldn't be ran with args");
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (-1);
	printf("%s\n", pwd);
	return (free(pwd), 0);
}
