/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:04:22 by tmalidi           #+#    #+#             */
/*   Updated: 2023/07/16 08:47:26 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//hgeffroy

//Probbalement a remplir vers la fin du projet, pour le moment on peut travailler avec nos .h chacun et on mettra en commun vers la fin ?

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_pipelist {
	char 				*elt;
	int  				type;
	struct s_pipelist	*next;
}  t_pipelist;

typedef struct s_list {
	int					nb; //qui serait le numero du pipe
	t_pipelist 			*pipelist;
	struct s_list		*next;
}  t_list;

#endif