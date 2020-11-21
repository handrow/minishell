/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:35:34 by handrow           #+#    #+#             */
/*   Updated: 2020/11/21 15:12:23 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_hidden.h"

int		ft_putch_n(int fd, char c, int n)
{
	const int	m = n < 0 ? 0 : n;

	while (n-- > 0)
	{
		if (write(fd, &c, 1) < 0)
			return (-1);
	}
	return (m);
}

int		ft_putstr_n(int fd, const char *str, int n)
{
	const int	s = (int)ft_strlen(str);

	return ((int)write(fd, str, s < n ? s : n));
}

int		ft_digit_len(unsigned long long num, int base)
{
	int count;

	count = 0;
	while (num != 0)
	{
		num /= base;
		count++;
	}
	return (count);
}

int		ft_putnbr(int fd, unsigned long long n, int base, int upper_case)
{
	const char	*alph = upper_case ? "0123456789ABCDEF" : "0123456789abcdef";
	int			a;
	int			b;

	if (base < 2 || base > 16)
		return (-1);
	if (n >= (unsigned long long)base)
	{
		a = ft_putnbr(fd, n / base, base, upper_case);
		if (a < 0)
			return (-1);
		b = ft_putnbr(fd, n % base, base, upper_case);
		if (b < 0)
			return (-1);
		return (a + b);
	}
	return ((int)write(fd, alph + n, 1));
}
