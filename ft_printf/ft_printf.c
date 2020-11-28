/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 22:06:30 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 05:40:20 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_hidden.h"

int				ft_printf(int fd, const char *str, ...)
{
	size_t		i;
	int			print_counter;
	int			printed_symbols;
	va_list		args;

	i = 0;
	print_counter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			printed_symbols = (int)write(fd, &str[i++], 1);
		else if (str[++i] != '\0')
			printed_symbols = print_value(fd,
						parse_format_flags(str, &i, &args));
		if (printed_symbols < 0)
		{
			print_counter = printed_symbols;
			break ;
		}
		print_counter += printed_symbols;
	}
	va_end(args);
	return (print_counter);
}
