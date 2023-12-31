/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:36:40 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/10/03 08:09:43 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

// Struct
typedef struct s_env
{
	char			*var;
	char			*value;
	struct s_env	*next;
}					t_env;

// Proto
char	*get_value_env(t_env *env, char *var);
char	**env_to_tab(t_env *env);
int		add_to_env(t_env **env, char *var, char *value);
int		env_len(t_env *env);
int		free_env_and_exit(t_env **env);
int		rm_from_env(t_env **env, char *var_to_rm);
int		set_value_env(t_env **env, char *var, char *value);
t_env	*check_add_env(t_env **env, char *var, char *value);
t_env	*create_env(char **env);
t_env	*env_lfvar(t_env *env, char *var);
t_env	*env_newelt(char *newvar, char *newvalue);
void	env_print(t_env *env);
void	env_free_elt(t_env *elt);
void	free_env(t_env *env);
void	free_tab(char **tab);

#endif