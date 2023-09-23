/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:04:24 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/23 08:00:14 by hgeffroy         ###   ########.fr       */
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

	tmp = env;
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

int	export_b(t_data *data)
{
	int		i;
	char	**args_s;

	g_return_value = 0;
	if (len_tab(data->args) < 2)
		print_export(*data->env);
	else if (is_an_option(data->args, 0) == YES)
		return (error_manager("export", OPTION), g_return_value);
	else
	{
		i = 0;
		while ((data->args)[++i])
		{
			args_s = parsing_export(data->args[i]);
			if (!args_s)
				continue ;
			else if (ft_strcmp((*data->env)->var, args_s[0]) \
			&& !env_lfvar(*data->env, args_s[0]))
				add_to_env(data->env, ft_strdup(args_s[0]), ft_strdup(args_s[1]));
			else if (args_s[1])
				set_value_env(data->env, args_s[0], args_s[1]);
			free_tab(args_s);
		}
	}
	return (g_return_value);
}
