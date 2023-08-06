/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:53:06 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/06 12:17:06 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	range(char *str, char *var, int size)
{
	int i;
	int j;
	
	i = 0;
	while(i < size)
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

char *rp_env(char *str, char *var, char *value)
{
	char *sec;
	char *tmp;
	char *final;
	int 	len;
	
	sec = ft_strnstr(str, var,ft_strlen(str));
	if (sec == NULL)
		return (NULL);
	sec += ft_strlen(var);
	len = range(str,var,ft_strlen(str));
	tmp = ft_substr(str, 0, len - (int)ft_strlen(var));
	final = ft_strjoin(tmp, value);
	free(tmp);
	tmp = ft_strjoin(final, sec);
	free(final);
	//free(sec);
	return (tmp);
}

int main()
{
	//printf("%s",ft_strnstr("je $USER suis beau", "$USER", ft_strlen("je $USER suis")));
	char *str;
	char *tmp;
	int i;
	
	i = 0;
	str = ft_strdup("je suis $USERf oui $USER");
	while (i < 2)
	{
		tmp = rp_env(str,"$USER", "tmalidi");
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	printf("%s", str);
	free(str);
}