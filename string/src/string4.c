/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbengued <zbengued@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 23:24:19 by zbengued          #+#    #+#             */
/*   Updated: 2025/06/20 00:04:11 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char string_shift(t_string *str)
{
    char c;

    if (!str || !str->size)
        return ('\0');
    c = str->data[0];
    ft_memmove(str->data, str->data + 1, str->size);
    str->size--;
    str->data[str->size] = '\0';
    return (c);
}

void string_shift_by(t_string *str, size_t offset)
{
    if (!str || offset >= str->size)
        return (string_clear(str));
    ft_memmove(str->data, str->data + offset, str->size - offset + 1);
    str->size -= offset;
}

void string_shift_while(t_string *str, char *charset)
{
    if (!str || !charset)
        return;
    while (str->size > 0 && ft_strchr(charset, str->data[0]))
        string_shift(str);
}

void	string_replace(t_string *str, char *old_str, char *new_str)
{
	size_t	old_len;
	size_t	new_len;
	size_t	pos;

	if (!str || !old_str || !new_str || !old_str)
		return ;
	old_len = ft_strlen(old_str);
	new_len = ft_strlen(new_str);
	pos = 0;
	while (pos <= str->size - old_len)
	{
		if (!ft_strncmp(str->data + pos, old_str, old_len))
		{
			string_segment_replace(str, pos, old_len, new_str);
			pos += new_len;
		}
		else
			pos++;
	}
}
