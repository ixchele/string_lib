/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbengued <zbengued@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:40:02 by zbengued          #+#    #+#             */
/*   Updated: 2025/06/20 23:07:42 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

t_string	string_substr(t_string *str, size_t start, size_t len)
{
	t_string	sub;

	string_init(&sub);
	if (!str || start >= str->size)
		return (sub);
	if (start + len > str->size)
		len = str->size - start;
	string_ensure_capacity(&sub, len);
	ft_memcpy(sub.data, str->data + start, len);
	sub.data[len] = '\0';
	sub.size = len;
	return (sub);
}

static void	string_fill_split(t_string *str, char d, t_string *arr, size_t c)
{
	size_t	i;
	size_t	start;
	size_t	part;

	i = 0;
	start = 0;
	part = 0;
	while (i <= str->size && part < c)
	{
		if (i == str->size || str->data[i] == d)
		{
			if (i > start)
				arr[part++] = string_substr(str, start, i - start);
			while (i < str->size && str->data[i] == d)
				i++;
			start = i;
		}
		else
			i++;
	}
}

t_string	*string_split(t_string *s, char delimiter, size_t *count)
{
	t_string	*parts;

	if (!s || !count)
		return (NULL);
	*count = string_segments_count(s, delimiter);
	if (*count == 0)
		return (NULL);
	parts = ft_calloc((*count), sizeof(t_string));
	if (!parts)
		return (NULL);
	string_fill_split(s, delimiter, parts, *count);
	return (parts);
}
