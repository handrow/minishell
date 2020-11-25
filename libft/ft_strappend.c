/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 22:14:31 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/25 22:42:57 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strappend(char **s1, char const *s2)
{
	char	*dst;
	size_t	lens1;
	size_t	lens2;

	if (!s2)
		return (0);
	if (!(*s1))
	{
		*s1 = ft_strdup(s2);
		return (*s1);
	}
	lens1 = (ft_strlen(*s1));
	lens2 = (ft_strlen(s2));
	dst = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!dst)
		return (0);
	ft_strlcpy(dst, *s1, lens1 + 1);
	ft_strlcat(dst, s2, lens1 + lens2 + 1);
	free(*s1);
	*s1 = dst;
	return (dst);
}
