/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 08:40:00 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/30 15:50:41 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int	**split_line(char *line, char **line_splitted);

static char	*get_var(char *line)
{
	int		i;
	char	*var;

	i = -1;
	while(line[++i] != '=')
	var = (char *)malloc(sizeof(char) * (i + 2));
	if (!var)
		return (NULL);
	ft_strlcpy(var, line, i);
	var[i] = '\0';
	return (var);
}

t_env	*create_env(char **env)
{
	int		i;
	char	*var;
	t_env	*lst_env;

	//if (!env) a gerer, on fait quoi ?
	
	lst_env = NULL;
	i = -1;
	while (env[++i])
	{
		var = get_var(env[i]);
		if (!var)
			return (/*Nettoyer l_env et free var*/NULL);
		if (add_to_env(lst_env, var, getenv(var)) < 0);
			return (/*Nettoyer l_env et free var*/NULL);
	}
	return (free(var), lst_env);
}

// A tester !

int	main(int ac, char *av, char **env)
{
	t_env *l_env;
	
	l_env = create_env(env);
	printf("%s\n", l_env->var);
	//env_print(l_env);
}

// gcc ../libft/*.c env_create.c env_free.c env_op.c env_to_tab.c env_utils.c -fsanitize=address