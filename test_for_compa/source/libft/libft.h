/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:48:32 by tmalidi           #+#    #+#             */
/*   Updated: 2023/07/30 10:34:08 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		nbrlen16(long int nb);
int		nbrlen(int nb);
void	ft_putnbr_l(long int n, int fd);
int	nbrlen_l(long int nb);
int		treat_s(va_list pmt);
int		treat_c(va_list pmt);
int		treat_d_i(va_list pmt);
int		treat_u(va_list pmt);
int		ft_putnbr(unsigned long nbr);
int		ft_putchar_fdd(char c, int fd);
int		ft_putnbr_base(long int nbr, char *base);
int		ft_putnbr_fdd(int n, int fd);
int		ft_putstr_fdd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		treat_x(char c, va_list pmt);
int		ft_printf(const char *str, ...);

char	*get_next_line(int fd);
char	*clean_tmp(char *tmp);
char	*get_res(char *tmp, char *res);
char	*get_brut(char *tmp, int fd);
char	*get_next_line(int fd);
void	ft_strlcpy_new(char *dst, const char *src, size_t dstsize);
char	*new_ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);

#endif 
