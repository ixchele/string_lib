/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbengued <zbengued@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:25:41 by zbengued          #+#    #+#             */
/*   Updated: 2025/06/19 18:44:16 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <libft.h>

# define INIT_CAPACITY 16

typedef struct s_string
{
	char	*date;
	size_t	size;
	size_t	capacity;
	size_t	peek;
}	t_string;

#endif
