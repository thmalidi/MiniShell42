/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:03:17 by tmalidi           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/03 10:57:59 by tmalidi          ###   ########.fr       */
=======
/*   Updated: 2023/09/30 07:05:12 by hgeffroy         ###   ########.fr       */
>>>>>>> 70996a9ecaa0876fc655df9adc22d80d6c84e472
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	interpreted(char *str, int range)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (i < range)
	{
		if (str[i] == 39 && between(str, i))
			q++;
		i++;
	}
	if (q % 2 == 0)
		return (1);
	return (0);
}

char	*make_str(char **tab)
{
	int		i;
	char	*final;
	char	*tmp;

	i = 0;
	final = malloc(sizeof(char));
	if (!final)
		return (NULL);
	final[0] = '\0';
	while (tab[i])
	{
		tmp = ft_strjoin(final, " "); //Proteger
		free(final);
		final = ft_strjoin(tmp, tab[i++]); //proteger
		free(tmp);
	}
	return (final);
}

char	*mod_env(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == ':')
		{
			free(tab[i]);
			tab[i] = ft_strdup("YES"); //Proteger ici
		}
		i++;
	}
	return (make_str(tab));
}

char	*expand(char *str, t_env **env)
{
	char	*final;
	char	**tab;
	char	*tmp;
	int		i;

	i = 0;
	tab = init(str);
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		if (i != 0 && (!ft_strcmp(tab[i - 1], "<")
				|| !ft_strcmp(tab[i - 1], ">>")
				|| !ft_strcmp(tab[i - 1], ">")) && tab[i][0] == '$'
				&& !get_value_env(*env, tab[i] + 1))
			return (free_tab(tab), ft_strdup("\6\0"));
		if (i != 0 && !ft_strcmp(tab[i - 1], "<<"))
			tab[i] = tab[i];
		else
			tab[i] = expand_process(tab[i], *env);
		i++;
	}
	tmp = join_tab(tab, 1);
	final = ft_strtrim(tmp, " ");
	return (free_tab(tab), free(tmp), final);
}
