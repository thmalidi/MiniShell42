/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:55:24 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/22 09:02:16 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdint.h>

# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_strnequ(const char *s1, const char *s2, size_t n);
int		ft_lstsize(t_list *lst);

size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strnstr(const char *meule_de_foin, const char *aiguille, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_itoa(int n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strtrim(const char *s, const char *set);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	**ft_split(const char *s, char c);

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_bzero(void *s, size_t n);
void	ft_lstadd_front(t_list **lst, t_list *newelt);
void	ft_lstadd_back(t_list **lst, t_list *newelt);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif