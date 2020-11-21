/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:05:12 by jiandre           #+#    #+#             */
/*   Updated: 2020/06/01 16:54:01 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strrchr(const char *str, int c)
{
	const char *sym;
	const char *tmp = NULL;

	if (!c)
		return ((char *)str + ft_strlen(str));
	sym = ft_strchr(str, c);
	while (sym)
	{
		tmp = sym;
		sym = ft_strchr(sym + 1, c);
	}
	return ((char *)tmp);
}
