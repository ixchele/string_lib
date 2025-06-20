/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbengued <zbengued@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:25:41 by zbengued          #+#    #+#             */
/*   Updated: 2025/06/20 10:11:06 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <libft.h>

# define INIT_CAPACITY 16

typedef struct s_string
{
	char	*data;
	size_t	size;
	size_t	capacity;
	size_t	peek;
}	t_string;

void		string_init(t_string *str);
void		string_destroy(t_string *str);
void		string_ensure_capacity(t_string *str, size_t needed_capacity);
void		string_set(t_string *str, char *new_data);

void		string_clear(t_string *str);
void		string_insert(t_string *str, size_t pos, char *to_insert);
void		string_erase(t_string *str, size_t pos, size_t len);
void		string_append(t_string *str, char *to_add);
void		string_prepend(t_string *str, char *to_add);
void		string_replace(t_string *str, char *old_str, char *new_str);
void		string_repeat(t_string *str, size_t n);

ssize_t		string_find(t_string *str, char *to_find);

t_string	string_join(t_string *array, size_t len, char *delimiter);
t_string	*string_split(t_string *s, char delimiter, size_t *count);

char		string_peek(t_string *str);
char		string_peek_advance(t_string *str);
char		string_peek_reset(t_string *str);

char		string_shift(t_string *str);
void		string_shift_by(t_string *str, size_t offset);
void		string_shift_while(t_string *str, char *charset);

int			string_match(t_string *str, char *target,
				int (*cmp)(const char *, const char *, size_t), size_t start);
void		string_segment_remove(t_string *string, size_t start,
				size_t length);
size_t		string_segments_count(t_string *str, char delimiter);
char		*string_segment_extract(t_string *str, size_t start, size_t length);
char		*string_segment_slice(t_string *str, size_t start, size_t length);
void		string_segment_replace(t_string *str, size_t start,
				size_t length, char *new_text);

#endif
