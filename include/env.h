/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 08:43:58 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/31 16:17:31 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../libft/libft.h"

// A delete
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>

// Struct
typedef struct s_env
{
	char			*var;
	char			*value;
	struct s_env	*next;
}					t_env;

// Proto
t_env	*create_env(char **env);
int		add_to_env(t_env **env, char *var, char *value);
int		rm_from_env(t_env **env, char *var_to_rm);
int		set_value(t_env *env, char *var, char *value);
t_env	*env_newelt(char *newvar, char *newvalue);
t_env	*env_lfvar(t_env *env, char *var);
void	env_print(t_env *env);
void	env_free_elt(t_env *elt);
void	env_clean(t_env *env);
char	**env_to_tab(t_env *env);
void	free_tab(char **tab);

#endif