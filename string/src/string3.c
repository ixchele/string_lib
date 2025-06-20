/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbengued <zbengued@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 23:17:13 by zbengued          #+#    #+#             */
/*   Updated: 2025/06/19 23:24:09 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	string_peek(t_string *str)
{
	if (!str || str->peek >= str->size)
		return ('\0');
	return (str->data[str->peek]);
}

char	string_peek_advance(t_string *str)
{
	if (!str || str->peek >= str->size)
		return ('\0');
	return (str->data[str->peek++]);
}

char	string_peek_reset(t_string *str)
{
	if (!str || !str->size)
		return ('\0');
	str->peek = 0;
	return (str->data[0]);
}

void	string_prepend(t_string *str, char *to_add)
{
	size_t	len_toadd;

	if (!str || !to_add)
		return ;
	len_toadd = ft_strlen(to_add);
	string_ensure_capacity(str, str->size + len_toadd);
	ft_memmove(str->data + len_toadd, str->data, str->size + 1);
	ft_memcpy(str->data, to_add, len_toadd);
}

void	string_repeat(t_string *str, size_t n)
{
	size_t	og_len;
	size_t	i;

	if (!str || !n)
		return ;
	og_len = str->size;
	i = 0;
	string_ensure_capacity(str, og_len * str->size);
	while (i < n)
	{
		ft_memcpy(str->data + og_len, str->data, og_len);
		i++;
	}
	str->size = og_len * n;
	str->data[str->size] = '\0';
}
