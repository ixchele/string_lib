/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbengued <zbengued@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 23:39:06 by zbengued          #+#    #+#             */
/*   Updated: 2025/06/20 00:09:07 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

int	string_match(t_string *str, char *target,
		int (*cmp)(const char *, const char *, size_t), size_t start)
{
	size_t	len;

	if (!str || !target || !cmp || start >= str->size)
		return (0);
	len = ft_strlen(target);
	if (start + len > str->size)
		return (0);
	return (!cmp(str->data + start, target, len));
}

void	string_segment_remove(t_string *string, size_t start, size_t length)
{
	if (!string || start >= string->size)
		return ;
	if (start + length > string->size)
		length = string->size - start;
	ft_memmove(string->data + start, string->data + start + length,
		string->size - (start + length) + 1);
	string->size -= length;
}

void	string_segment_replace(t_string *str, size_t start,
		size_t length, char *new_text)
{
	if (!str || !new_text)
		return ;
	string_segment_remove(str, start, length);
	string_insert(str, start, new_text);
}

char	*string_segment_extract(t_string *str, size_t start, size_t length)
{
	char	*result;

	if (!str || start >= str->size)
		return (NULL);
	if (start + length > str->size)
		length = str->size - start;
	result = ft_calloc(length + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, str->data + start, length);
	result[length] = '\0';
	return (result);
}

char	*string_segment_slice(t_string *str, size_t start, size_t length)
{
	return (string_segment_extract(str, start, length));
}
