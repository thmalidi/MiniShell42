/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:12:22 by tmalidi           #+#    #+#             */
/*   Updated: 2023/08/08 17:23:38 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int replace(char *str, char c, int i)
{
    while(str[i] && str[i] != c)
    {
        printf("str[i] = %c\n", str[i]);
        if (str[i] == ' ')
            str[i] = c;
        i++;
    }
    return(i + 1);
}

void quote_splite(char *str)
{
    int i;

    if (!double_quote(str))
        return ;
    i = 0;
    while (str[i])
    {
        while(str[i] != 39 && str[i] != 34 && str[i])
            i++;
        if (str[i] != '\0')
            i = replace(str,str[i],i + 1);
    }
}

void clean_str(char *str)
{
    int i;

    i = 1;
    while(str[i] && str[i + 1])
    {
        if (str[i] == 39 || str[i] == 34)
        {
            if (str[i] == str[0])
                str[i] = ' ';
        }
        i++;
    }
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