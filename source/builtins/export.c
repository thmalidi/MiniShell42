/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:04:24 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/17 06:16:04 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_export_line(t_env *env_var)
{
	if (!env_var)
		return (-1);
	printf("declare -x ");
	printf("%s", env_var->var);
	if (env_var->value)
	{
		printf("=\"");
		printf("%s\"", env_var->value);
	}
	printf("\n");
	return (0);
}

t_env	*find_next_min(t_env *env, char *prev_min)
{
	t_env	*min;
	t_env	*tmp;

	tmp = env; // Check que l'env est pas vide
	min = NULL;
	while (tmp)
	{
		if (strcmp(tmp->var, prev_min) > 0)
			min = tmp;
		tmp = tmp->next;
	}
	if (!min)
		return (NULL);
	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(min->var, tmp->var) > 0 \
		&& ft_strcmp(prev_min, tmp->var) < 0)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

int	print_export(t_env *env)
{
	int		i;
	t_env	*min;
	char	*prev_min;

	i = 0;
	prev_min = "";
	while (i < env_len(env))
	{
		min = find_next_min(env, prev_min);
		print_export_line(min);
		prev_min = min->var;
		i++;
	}
	return (0);
}

int	export_b(t_datalist *data, t_env **env)
{
	int		i;
	t_env	*tmp;
	char	**args_splitted;

	if (len_tab(data->args) < 2)
		print_export(*env);
	else
	{
		i = 0;
		while ((data->args)[++i])
		{
			tmp = *env;
			args_splitted = parsing_export(data->args[i]);
			if (!args_splitted)
				continue ;
			else if (strcmp((*env)->var, args_splitted[0]) \
			&& !env_lfvar(tmp, args_splitted[0]))
				add_to_env(env, args_splitted[0], args_splitted[1]);
			else
				set_value_env(env, args_splitted[0], args_splitted[1]);
			free(args_splitted);
		}
	}
	return (0);
}

// int	main(int ac, char **av, char **env)
// {
// 	t_env *tenv;

// 	(void)ac;
// 	(void)av;
// 	tenv = create_env(env);
// 	print_export(tenv);
// 	return (0);
// }