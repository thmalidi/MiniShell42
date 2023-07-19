/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:11:20 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/19 08:16:46 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "exec.h"

typedef struct s_pipelist {
	char 				*elt;
	int  				type;
	struct s_pipelist	*next;
}  t_pipelist;

typedef struct s_list {
	int					lastpipe; // 1 si c'est le dernier pipe 0 sinon.
	t_pipelist 			*pipelist;
	struct s_list		*next;
}  t_list;

typedef	int	(*t_redirect)(int *fd, t_pipelist *pipelist);

#endif