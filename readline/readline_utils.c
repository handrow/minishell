/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 04:30:23 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/21 05:40:22 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*find_first_sym(char *s, char *syms)
{
	size_t	len;

	len = ft_strlen(syms);
	while (*s)
	{
		if (ft_memchr(syms, *s, len))
			return (s);
		++s;
	}
	return (NULL);
}
