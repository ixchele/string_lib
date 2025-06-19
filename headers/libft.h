/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:50:35 by ihajji            #+#    #+#             */
/*   Updated: 2025/06/18 17:43:07 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define SUCCESS 0
# define CMD_NOT_FOUND 127
# define ERROR -1
# define FAILIURE 1
# define FALSE 0
# define TRUE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_darr
{
	void	**items;
	size_t	capacity;
	size_t	size;
}	t_darr;

void				darr_init(t_darr *arr);
void				darr_push(t_darr *arr, void *item);
void				darr_free_arr(t_darr *arr, void (*f)(void *));
int					ft_atoi(const char *nptr);
long				ft_atol(const char *nptr);
double				ft_atof(char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isblank(int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t dsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_strisempty(char *str);
int					ft_strisdecimal(char *str);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_itoa(int n);
int					ft_strisnum(char *str);
char				*ft_strndup(const char *src, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(const char *s, char c);
char				*ft_strtrim(const char *s, const char *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_putchar_fd(char c, int fd);
int					ft_putendl_fd(char *s, int fd);
int					ft_putnbr_fd(int n, int fd);
int					ft_putstr_fd(char *s, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstpush(t_list **from, t_list **to);
void				ft_lstreverse_rotate(t_list **head);
void				ft_lstrotate(t_list **head);
void				ft_lstswap(t_list **head);
int					ft_printf(const char *fmt, ...);
int					ft_dprintf(int fd, const char *fmt, ...);
int					ft_execvpe(char *file, char **av, char **envp);
char				**ft_tokenize(char const *s);
char				*ft_getenv(char **envp, char *var);
char				**ft_getpath(char *path);
void				**ft_free_vector(char **vector);

#endif // !LIBFT_H
