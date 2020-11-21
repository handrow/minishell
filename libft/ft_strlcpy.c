/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:21:31 by jiandre           #+#    #+#             */
/*   Updated: 2020/05/12 10:57:54 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*d;

	if (!dst || !src)
		return (0);
	d = dst;
	if (size != 0)
		d = ft_memccpy(dst, src, '\0', size - 1);
	if (!d && size != 0)
		*(dst + size - 1) = '\0';
	return (ft_strlen(src));
}
