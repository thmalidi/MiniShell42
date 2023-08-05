/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:03:17 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/05 18:59:33 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int interpreted(char *str)
{
    int i;

    i = 0;
    if (str[0] != 39)
    {
        while(str[i])
        {
            if (str[i] == '$')
                return (1);
            i++;
        }
    }
    return (0);
}

char *make_str(char **tab)
{
    int i;
    char *final;
    char *tmp;

    i = 0;
    final = malloc(sizeof(char));
    final[0] = '\0';
    while (tab[i])
    {
        tmp = ft_strjoin(final, " ");
        free(final);
        final = ft_strjoin(tmp, tab[i++]);
        free(tmp);
    }
    return (final);
}

char *mod_env(char **tab)
{
    int i;
    
    i = 0;
    while (tab[i])
    {
        if (tab[i][0] == ':')
        {
            free(tab[i]);
            tab[i] = ft_strdup("YES");
        }
        i++;
    }
    return (make_str(tab));
}

int main()
{
    char **tab = ft_split("je suis$:USER", '$');
    char *final = mod_env(tab);
    ft_printf("%s",final);
    free_tab(tab);
    free(final);
}