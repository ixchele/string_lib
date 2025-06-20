/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbengued <zbengued@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:04:49 by zbengued          #+#    #+#             */
/*   Updated: 2025/06/20 23:08:13 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

static size_t	string_total_size(t_string *arr, size_t len, size_t delim_len)
{
	size_t	total;
	size_t	i;

	total = 0;
	i = 0;
	while (i < len)
	{
		total += arr[i].size;
		if (i < len - 1)
			total += delim_len;
		i++;
	}
	return (total);
}

static void	string_fill(t_string *result, t_string *arr, size_t len, char *d)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		string_append(result, arr[i].data);
		if (i < len - 1 && d)
			string_append(result, d);
		i++;
	}
}

t_string	string_join(t_string *array, size_t len, char *delimiter)
{
	t_string	result;
	size_t		delim_len;
	size_t		total;

	string_init(&result);
	if (!array || len == 0)
		return (result);
	delim_len = 0;
	if (delimiter)
		delim_len = ft_strlen(delimiter);
	total = string_total_size(array, len, delim_len);
	string_ensure_capacity(&result, total);
	string_fill(&result, array, len, delimiter);
	return (result);
}
