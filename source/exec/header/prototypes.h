/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:05:49 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/19 11:18:21 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "exec.h"
# include "struct.h"

// Redir
int		check_redir(t_pipelist *pipelist, int *fd);

// Free
void	free_tab(char **tab);

// Utils
void	close_all(int *fd);

#endif