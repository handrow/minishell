/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 07:25:17 by jiandre           #+#    #+#             */
/*   Updated: 2020/08/27 03:25:43 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr_fd(long n, int fd)
{
	char			symb;
	unsigned long	m;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	m = (unsigned long)n;
	if (m >= 10)
	{
		ft_putnbr_fd(m / 10, fd);
		symb = (m % 10) + '0';
		write(fd, &symb, 1);
	}
	if (m >= 0 && m <= 9)
	{
		symb = m + '0';
		write(fd, &symb, 1);
	}
}
