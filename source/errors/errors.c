/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:56:51 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/11 16:10:32 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	error_manager(char *str, int error_id)
{
	const t_errors	tab_errors[] = {&error_nofile, &error_isdir, &error_notdir, \
									&error_cmd, &error_perm, &error_syntax, \
									&error_identifier, &error_args, \
									&error_malloc, &error_option};

	return ((*tab_errors[error_id])(str));
}
