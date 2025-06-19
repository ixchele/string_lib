/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbengued <zbengued@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:25:41 by zbengued          #+#    #+#             */
/*   Updated: 2025/06/19 23:49:01 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <libft.h>

# define INIT_CAPACITY 16

typedef struct s_string
{
	char	*data;
	size_t	size;
	size_t	capacity;
	size_t	peek;
}	t_string;

void	string_init(t_string *str);
void	string_destroy(t_string *str);
void	string_ensure_capacity(t_string *str, size_t needed_capacity);
void	string_set(t_string *str, char *new_data);

void	string_clear(t_string *str);
void	string_insert(t_string *str, size_t pos, char *to_insert);
void	string_erase(t_string *str, size_t pos, size_t len);
void	string_append(t_string *str, char *to_add);
void	string_replace(t_string *str, char *old_str, char *new_str);

ssize_t	string_find(t_string *str, char *to_find);

char	string_peek(t_string *str);
char	string_peek_advance(t_string *str);
char	strinf_peek_reset(t_string *str);

char	string_shift(t_string *str);
void	string_shift_by(t_string *str, size_t offset);
void	string_shift_while(t_string *str, char *charset);

int		string_match(t_string *str, char *target,
		int (*cmp)(const char *, const char *, size_t), size_t start);
void	string_segment_remove(t_string *string, size_t start, size_t length);
char	*string_segment_extract(t_string *str, size_t start, size_t length);
char	*string_segment_slice(t_string *str, size_t start, size_t length);
void	string_segment_replace(t_string *str, size_t start,
		size_t length, char *new_text);
#endif
