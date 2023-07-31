/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 08:40:00 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/31 10:15:58 by hgeffroy         ###   ########.fr       */
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
	var = (char *)malloc(sizeof(char) * (i + 3));
	if (!var)
		return (NULL);
	ft_strlcpy(var, line, i + 1);
	var[i + 1] = '\0';
	return (var);
}

t_env	*create_env(char **env)
{
	int		i;
	char	*var;
	t_env	*lst_env;

	int		test;

	//if (!env) a gerer, on fait quoi ?
	
	lst_env = NULL;
	i = -1;
	while (env[++i])
	{
		var = get_var(env[i]);
		printf("var[%d] = %s\n", i, var);
		if (!var)
			return (/*Nettoyer l_env et free var*/NULL);
			
		test = add_to_env(&lst_env, var, getenv(var));
		// printf("lst_env->var = %s\n", lst_env->var);
		printf("test1 = %d\n", test);
		if (test == 61);
		{
			printf("test666 = %d\n", test);
			return (/*Nettoyer l_env et free var*/NULL);
		}
		printf("We passed !!");
	}
	// puts("YO from create_env");
	return (lst_env);
}

// A tester !

int	main(int ac, char *av, char **env)
{
	t_env *l_env;
	
	l_env = create_env(env);
	//env_print(l_env);
}

// gcc ../libft/*.c env_create.c env_free.c env_op.c env_to_tab.c env_utils.c -fsanitize=address -g3