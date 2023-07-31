/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 08:40:00 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/31 16:25:52 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static char	*get_var(char *line)
{
	int		i;
	char	*var;

	i = 0;
	while (line[i] != '=')
		i++;
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
	
	lst_env = NULL;
	i = -1;
	while (env[++i])
	{
		var = get_var(env[i]);
		if (!var)
			return (env_clean(lst_env), free(var), NULL);	
		if (add_to_env(&lst_env, ft_strdup(var), ft_strdup(getenv(var))))
			return (env_clean(lst_env), free(var), NULL);
		free(var);
	}
	return (lst_env);
}

// A tester !

void print_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		printf("tab[%d] = %s\n", i, tab[i]);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	
	t_env *l_env;
	char  **tabenv;
	
	l_env = create_env(env);
	env_print(l_env);
	tabenv = env_to_tab(l_env);
	env_clean(l_env);
	printf("\n\n\n\n");
	print_tab(tabenv);
	free_tab(tabenv);
}

// gcc ../libft/*.c env_create.c env_free.c env_op.c env_to_tab.c env_utils.c -fsanitize=address -g3 -Werror -Wextra -Wall