/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 00:55:34 by jiandre           #+#    #+#             */
/*   Updated: 2020/05/18 13:56:44 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *nptr)
{
	int			atoint;
	int			sign;
	int			pnb;

	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if ((*nptr == '+') || (*nptr == '-'))
		nptr++;
	atoint = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		pnb = atoint;
		atoint = atoint * 10 - '0' + *nptr++;
		if (pnb != atoint / 10 && (atoint & 0x7FFF))
			return ((sign > 0) ? -1 : 0);
	}
	return (atoint * sign);
}
