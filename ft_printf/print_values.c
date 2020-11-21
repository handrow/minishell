/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:43:57 by handrow           #+#    #+#             */
/*   Updated: 2020/11/21 15:12:17 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_hidden.h"

static int	print_formatted_number(int fd, t_flags v_flags, int base,
						const char *prefix)
{
	const int	prefix_len = ft_strlen(prefix);
	const int	num_len = ft_digit_len(v_flags.value, base);
	int			zeroes;
	int			spaces;
	int			count;

	zeroes = v_flags.zero_filling && v_flags.alignment == PF_ALIGN_RIGHT
				? v_flags.width - (num_len + prefix_len) : 0;
	zeroes = v_flags.precision ? v_flags.precision_value - num_len : zeroes;
	zeroes = zeroes < 0 ? 0 : zeroes;
	spaces = v_flags.width - (zeroes + num_len + prefix_len);
	count = 0;
	if (v_flags.alignment == PF_ALIGN_RIGHT)
		count += ft_putch_n(fd, ' ', spaces);
	count += ft_putstr_n(fd, prefix, prefix_len);
	count += ft_putch_n(fd, '0', zeroes);
	if (num_len > 0)
		count += ft_putnbr(fd, v_flags.value, base, v_flags.type == PF_HEX_U);
	if (v_flags.alignment == PF_ALIGN_LEFT)
		count += ft_putch_n(fd, ' ', spaces);
	return (count);
}

static int	print_int(int fd, t_flags value_flags)
{
	const long long		value = (int)value_flags.value;

	if (value < 0)
	{
		value_flags.value = (unsigned int)(-value);
		return (print_formatted_number(fd, value_flags, 10, "-"));
	}
	return (print_formatted_number(fd, value_flags, 10, ""));
}

static int	print_sym(int fd, t_flags v_flags)
{
	const char	sym = (unsigned char)v_flags.value;
	int			zeroes;
	int			spaces;
	int			count;

	zeroes = v_flags.zero_filling && v_flags.alignment == PF_ALIGN_RIGHT
				? v_flags.width - 1 : 0;
	spaces = v_flags.width - (zeroes + 1);
	count = 0;
	if (v_flags.alignment == PF_ALIGN_RIGHT)
		count += ft_putch_n(fd, ' ', spaces);
	count += ft_putch_n(fd, '0', zeroes);
	count += ft_putch_n(fd, sym, 1);
	if (v_flags.alignment == PF_ALIGN_LEFT)
		count += ft_putch_n(fd, ' ', spaces);
	return (count);
}

static int	print_str(int fd, t_flags v_flags)
{
	const char	*str = (const char *)(v_flags.value);
	int			str_len;
	int			zeroes;
	int			spaces;
	int			count;

	str_len = (int)ft_strlen(str);
	str_len = v_flags.precision && v_flags.precision_value < str_len
			? v_flags.precision_value : str_len;
	zeroes = v_flags.zero_filling && v_flags.alignment == PF_ALIGN_RIGHT
				? v_flags.width - str_len : 0;
	spaces = v_flags.width - (zeroes + str_len);
	count = 0;
	if (v_flags.alignment == PF_ALIGN_RIGHT)
		count += ft_putch_n(fd, ' ', spaces);
	count += ft_putch_n(fd, '0', zeroes);
	count += ft_putstr_n(fd, str, str_len);
	if (v_flags.alignment == PF_ALIGN_LEFT)
		count += ft_putch_n(fd, ' ', spaces);
	return (count);
}

int			print_value(int fd, t_flags value_flags)
{
	if ((value_flags.type & 0b11111) && !value_flags.precision &&
	!(value_flags.zero_filling && value_flags.width && !value_flags.alignment))
	{
		value_flags.precision = 1;
		value_flags.precision_value = 1;
	}
	if (value_flags.type & PF_INT)
		return (print_int(fd, value_flags));
	if (value_flags.type & PF_UINT)
		return (print_formatted_number(fd, value_flags, 10, ""));
	if (value_flags.type & (PF_HEX_L | PF_HEX_U))
		return (print_formatted_number(fd, value_flags, 16, ""));
	if (value_flags.type & PF_ADR)
		return (print_formatted_number(fd, value_flags, 16, "0x"));
	if (value_flags.type & PF_SYM)
		return (print_sym(fd, value_flags));
	if (value_flags.type & PF_STR)
	{
		value_flags.value = value_flags.value == 0
			? (size_t)"(null)" : value_flags.value;
		return (print_str(fd, value_flags));
	}
	return (-1);
}
