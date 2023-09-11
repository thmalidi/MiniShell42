/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:12:22 by tmalidi           #+#    #+#             */
/*   Updated: 2023/09/11 15:42:15 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	between(char *str, int range)
{
	int i;
	int s;
	int d;

	i = 0;
	d = 0;
	s = 0;
	while (str[i] && i < range)
	{
		if (str[i] == 34)
			d++;
		if (str[i] == 39)
			s++;
		i++;
	}
	if (s % 2 == 0 && d % 2 == 0)
		return (1);
	return (0);
	
}


int	replace(char *str, char c, int i)
{
	while (str[i] && str[i] != c)
	{
		if (str[i] == ' ')
			str[i] = 1;
		i++;
	}
	return (i + 1);
}

void	quote_splite(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != 39 && str[i] != 34)
			i++;
		if (str[i])
			i = replace(str, str[i], i + 1);
	}
}

void	clean_str(char *str, int v)
{
	int	i;

	i = v;
	while (str[i] && str[i + 1])
	{
		if (v == 1 && str[i] == 1)
			str[i] = ' ';
		else if (v == 0 && str[i] == 1)
			str[i] = '\'';
		else if (v == 0 && str[i] == 2)
			str[i] = '\"';
		i++;
	}
}

char *end_clean(char *str)
{
	char	*dup;
	char	*tmp;
	char	**tab;
	int 	i;
	
	tmp = ft_strdup(prepare_string(str));
	free(str);
	tab = ft_split(tmp, 34);
	free(tmp);
	dup = join_tab(tab, 0);
	free_tab(tab);
	tab = ft_split(dup, 39);
	free(dup);
	tmp = join_tab(tab, 0);
	clean_str(tmp, 0);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == 1 || tmp[i] == 2)
			tmp[i] = '\0';
		i++;
	}
	return (free_tab(tab), tmp);
}

/*int main()
{
	char *str;
	str = ft_strdup("'ah'bon'freoe'");
	//quote_splite(str);
	clean_str(str);
	printf("%s",str);
	free(str);
}*/