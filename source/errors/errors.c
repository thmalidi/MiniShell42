/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:32:01 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/23 10:35:18 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_manager(char *str, int error_id)
{
	const t_errors	tab_errors[] = {&error_nofile, &error_isdir, &error_notdir, \
									&error_cmd, &error_perm, &error_syntax, \
									&error_identifier, &error_args, \
									&error_malloc, &error_option, \
									&error_quotes, &error_hd, &error_notset, \
									&error_ambiguous, &error_nopath};

	return ((*tab_errors[error_id])(str));
}
