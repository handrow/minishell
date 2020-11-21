/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:00:10 by jiandre           #+#    #+#             */
/*   Updated: 2020/07/24 01:37:31 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_num_len(long n, int base)
{
	int			len;

	len = 0;
	while (n > base - 1 || n < -(base - 1))
	{
		len++;
		n /= base;
	}
	len++;
	if (n < 0)
		len++;
	return (len);
}

static void		flags_init(t_flags *flgs)
{
	flgs->type = 0;
	flgs->width = 0;
	flgs->precn = 0;
	flgs->zero = 0;
	flgs->minus = 0;
	flgs->point = 0;
}

void			putsymbs(int symb, int len)
{
	while (len)
	{
		write(1, &symb, 1);
		len--;
	}
}

int				ft_printf_tflg(va_list args, size_t len, t_flags flgs)
{
	if (flgs.type == 's')
		len += ft_printf_s(va_arg(args, char*), flgs);
	else if (flgs.type == 'c')
		len += printf_c(flgs, (char)va_arg(args, int));
	else if (flgs.type == 'p')
		len += printf_p(flgs, va_arg(args, long), 16);
	else if (flgs.type == 'i' || flgs.type == 'd')
		len += printf_diux(flgs, (long)va_arg(args, int), 10, 0);
	else if (flgs.type == 'u')
		len += printf_diux(flgs, (long)va_arg(args, unsigned int), 10, 0);
	else if (flgs.type == 'x')
		len += printf_diux(flgs, (long)va_arg(args, unsigned int), 16, 0);
	else if (flgs.type == 'X')
		len += printf_diux(flgs, (long)va_arg(args, unsigned int), 16, 1);
	else if (flgs.type == '%')
		len += printf_c(flgs, '%');
	return (len);
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		len;
	t_flags		flgs;

	if (!str)
		return (-1);
	va_start(args, str);
	len = 0;
	while (*str != '\0')
	{
		while (*str != '%' && *str != '\0')
		{
			ft_putchar_fd(*(str++), 1);
			len++;
		}
		flags_init(&flgs);
		str = (*str != '\0') ? ft_print_pars(args, ++str, &flgs) : str;
		if (flgs.zero && flgs.minus)
			flgs.zero = 0;
		len = ft_printf_tflg(args, len, flgs);
	}
	va_end(args);
	return (len);
}
