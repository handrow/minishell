/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 22:14:31 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/28 06:25:12 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strappend(char **src, char const *apx)
{
	char			*new_str;
	const size_t	src_len = *src ? ft_strlen(*src) : 0;
	const size_t	apx_len = ft_strlen(apx);

	if (!(*src))
	{
		*src = ft_strdup(apx);
		return (*src);
	}
	new_str = (char *)malloc(sizeof(char) * (src_len + apx_len + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, *src, src_len);
	ft_memcpy(new_str + src_len, apx, apx_len);
	new_str[src_len + apx_len] = '\0';
	free(*src);
	*src = new_str;
	return (new_str);
}
