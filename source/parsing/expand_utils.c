/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:53:06 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/11 18:05:27 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	range(char *str, char *var, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (str[i] == var[0])
		{
			j = 0;
			while (str[i] == var[j] && (size_t)j < ft_strlen(var))
			{
				j++;
				i++;
				if ((size_t)j == ft_strlen(var))
					return (i);
			}
		}
		i++;
	}
	return (-1);
}

char	*rp_env(char *str, char *var, char *value)
{
	char	*sec;
	char	*tmp;
	char	*final;
	int		len;

	sec = ft_strnstr(str, var, ft_strlen(str));
	if (sec == NULL)
		return (NULL);
	sec += ft_strlen(var);
	len = range(str, var, ft_strlen(str));
	tmp = ft_substr(str, 0, len - (int)ft_strlen(var));
	if (value)
		final = ft_strjoin(tmp, value);
	else 
		final = ft_strdup(tmp);
	free(tmp);
	tmp = ft_strjoin(final, sec);
	free(final);
	return (tmp);
}

int	count_var(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i++] == '$')
			c += 1;
	}
	return (c);
}

char	**extract_var(char *str)
{
	int		i;
	int		j;
	int		c;
	char	**tab;

	tab = malloc(sizeof(char *) * (count_var(str) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			j = i + 1;
			while (str[j] && ft_isalnum(str[j]))
				j++;
			if (j - i != 1)
				tab[c++] = ft_substr(str, i, j - i);
		}
		i++;
	}
	tab[c] = NULL;
	return (tab);
}

char	*expand_process(char *str, t_env *env)
{
	char	**tab;
	int		i;
	char	*tmp;
	char	*final;

	i = 0;
	final = ft_strdup(str);
	free(str);
	if (final[0] != 39)
	{
		tab = extract_var(final);
		while (tab[i])
		{
			tmp = rp_env(final, tab[i], get_value_env(env, tab[i] + 1));
			free(final);
			final = ft_strdup(tmp);
			free(tmp);
			i++;
		}
		free_tab(tab);
	}
	return (final);
}
