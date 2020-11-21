/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:42:53 by jiandre           #+#    #+#             */
/*   Updated: 2020/05/07 07:49:24 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	size_t	dlen;

	d = dst;
	dlen = ft_strlen(dst);
	if (dlen >= size)
		return (size + ft_strlen(src));
	d = ft_memccpy(dst + dlen, src, '\0', size - dlen);
	if (!d)
		*(dst + size - 1) = '\0';
	return (ft_strlen(src) + dlen);
}
