/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbengued <zbengued@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 22:49:21 by zbengued          #+#    #+#             */
/*   Updated: 2025/06/19 23:48:50 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

void	string_clear(t_string *str)
{
	if (!str || !str->data)
		return ;
	str->size = 0;
	str->peek = 0;
	str->data[0] = '\0';
}

void	string_insert(t_string *str, size_t pos, char *to_insert)
{
	size_t	insert_len;

	if (!str || !to_insert || pos > str->size)
		return ;
	insert_len = ft_strlen(to_insert);
	string_ensure_capacity(str, str->size + insert_len);
	ft_memmove(str->data + pos + insert_len,
		str->data + pos,
		str->size - pos + 1);
	ft_memcpy(str->data + pos, to_insert, insert_len);
	str->size += insert_len;
}

void	string_erase(t_string *str, size_t pos, size_t len)
{
	if (!str || pos >= str->size)
		return ;
	if (pos + len > str->size)
		len = str->size - pos;
	ft_memmove(str->data + pos,
		str->data + pos + len, str->size - pos - len + 1);
	str->size -= len;
}

ssize_t	string_find(t_string *str, char *to_find)
{
	char	*found;

	if (!str || !to_find)
		return (-1);
	found = ft_strstr(str->data, to_find);
	if (!found)
		return (-1);
	return ((ssize_t)(found - str->data));
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
