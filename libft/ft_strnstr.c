/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:33:14 by jiandre           #+#    #+#             */
/*   Updated: 2020/05/19 17:51:14 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *bg, const char *ltle, size_t len)
{
	size_t		ltle_len;

	ltle_len = ft_strlen(ltle);
	if (!ltle[0])
		return ((char*)bg);
	while (*bg && ltle_len <= len--)
	{
		if (*bg == *ltle && !ft_strncmp(bg, ltle, ltle_len))
			return ((char *)bg);
		bg++;
	}
	return (0);
}
