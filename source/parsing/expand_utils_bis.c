/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:46:36 by tmalidi           #+#    #+#             */
/*   Updated: 2023/10/02 15:51:09 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*change(char *str, char *final, t_env *env, char *rv)
{
	char	*value;
	char	**tab;

	if (!str)
		return (NULL);
	value = get_value_env(env, str + 1);
	if (str[0] != '$')
		return (ft_strdup(str));
	if (!ft_strncmp("$?", str, ft_strlen(str)))
		return (rp_env(final, str, rv));
	else if (ft_isdigit(str[1]))
		return (rp_env(final, str, str + 2));
	else if (str[1] == 34 || str[1] == 39)
	{
		if (str[2] == str[1])
			return ("\0");
		tab = ft_split(str + 1, str[1]);
		return (join_tab(tab, 0));
	}
	else if (!value)
		return (rp_env(final, str, ""));
	else
		return (rp_env(final, str, value));
}

void	ending(char *tmp)
{
	int	i;

	if (!tmp)
		return ;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == 1)
			tmp[i] = '\'';
		if (tmp[i] == 2)
			tmp[i] = '\"';
		if (tmp[i] == 4)
			tmp[i] = '<';
		if (tmp[i] == 5)
			tmp[i] = '>';
		if (tmp[i] == -1)
			tmp[i] = '$';
		i++;
	}
}

t_big_list	*end_check(char *str, t_big_list	*arg, t_env **envlst)
{
	if (!double_quote(str))
		return (error_manager("\"", QUOTES), NULL);
	if (check_full_space(str))
		return (error_manager("|", SYNTAX), NULL);
	arg = pars_arg(str, envlst);
	return (arg);
}

char	**init(char *str)
{
	char	*tmp;
	char	**tab;

	tmp = ft_strdup(str);
	free(str);
	tab = ft_split(tmp, ' ');
	if (!tab[0])
		return (free(tab), NULL);
	return (free(tmp), tab);
}

void	free_r(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(tab[i++]);
}
