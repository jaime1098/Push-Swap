/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:41:56 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/22 18:51:14 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_node
{
	int				value;
	int				ideal;
	int				mova;
	int				movb;
	int				movt;
	int				rrota;
	int				rrotb;
	struct s_node	*next;
}				t_node;

typedef struct s_variable
{
	char	**splited;
	int		max;
	int		min;
	int		num;
	int		ideal;
	int		total;
	int		totalb;
	int		movb;
	int		totala;
	int		mova;
	int		racount;
}				t_variable;

int		ft_isalpha(int ch);
int		ft_isdigit(int n);
int		ft_isalnum(int n);
int		ft_isascii(int n);
int		ft_isprint(int ch);
int		ft_strlen(const char *str);
void	*ft_memset(void *str, int ch, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t strl);
size_t	ft_strlcat(char *dst, const char *src, size_t strl);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_memchr(const void *ptr, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_strnstr(const char *str, const char *obj, size_t n);
int		ft_atoi(t_variable *variable, t_node **stack_a, const char *numchar);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *str, unsigned int start, size_t length);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
