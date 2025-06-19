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

char	strinf_peek_reset(t_string *str)
{
	if (!str || !str->size)
		return ('\0');
	str->peek = 0;
	return (str->data[0]);
}
