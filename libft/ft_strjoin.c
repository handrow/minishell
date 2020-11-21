/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 05:34:43 by jiandre           #+#    #+#             */
/*   Updated: 2020/05/12 11:31:06 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (0);
	lens1 = (ft_strlen(s1));
	lens2 = (ft_strlen(s2));
	dst = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!dst)
		return (0);
	ft_strlcpy(dst, s1, lens1 + 1);
	ft_strlcat(dst, s2, lens1 + lens2 + 1);
	return (dst);
}
