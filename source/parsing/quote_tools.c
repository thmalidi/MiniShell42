/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:12:22 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/30 17:11:05 by tmalidi          ###   ########.fr       */
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
			str[i] = '~';
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

void	clean_str(char *str)
{
	int	i;

	i = 1;
	while (str[i] && str[i + 1])
	{
		if (str[i] == '~')
			str[i] = ' ';
		/*else if (str[i] == '@')
			str[i] = '~';*/
		/*if (str[i] == 39 || str[i] == 34)
		{
			if (str[i] == str[0])
				str[i] = ' ';
		}*/
		i++;
	}
}

char *end_clean(char *str)
{
	char *dup;
	char *tmp;
	char **tab;

	tmp = ft_strdup(str);
	free(str);
	tab = ft_split(tmp, 34);
	free(tmp);
	dup = join_tab(tab, 0);
	free_tab(tab);
	tab = ft_split(dup, 39);
	free(dup);
	tmp = join_tab(tab, 0);
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