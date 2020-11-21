/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 23:31:32 by jiandre           #+#    #+#             */
/*   Updated: 2020/05/05 21:26:26 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LOWBITS ((unsigned long)-1 / (unsigned char)-1)
#define HIGHBITS (LOWBITS << 7)

size_t						ft_strlen(const char *s)
{
	const unsigned char		*ch;
	unsigned long			oct_byte;

	ch = (unsigned char*)s;
	while (((unsigned long)ch & (sizeof(long) - 1)) != 0)
	{
		if (*ch == '\0')
			return ((size_t)ch - (size_t)s);
		ch++;
	}
	oct_byte = *((const unsigned long *)ch);
	while (((oct_byte - LOWBITS) & ~oct_byte & HIGHBITS) == 0)
	{
		ch = ch + sizeof(long);
		oct_byte = *((const unsigned long *)ch);
	}
	while (*ch)
		ch++;
	return ((size_t)ch - (size_t)s);
}
