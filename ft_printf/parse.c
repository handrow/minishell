/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:28:22 by handrow           #+#    #+#             */
/*   Updated: 2020/11/21 15:12:28 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_hidden.h"

static t_format_type	get_type(char c)
{
	if (c == 'i' || c == 'd')
		return (PF_INT);
	if (c == 'u')
		return (PF_UINT);
	if (c == 'x')
		return (PF_HEX_L);
	if (c == 'X')
		return (PF_HEX_U);
	if (c == 'p')
		return (PF_ADR);
	if (c == 'c')
		return (PF_SYM);
	if (c == 's')
		return (PF_STR);
	return (PF_UNKNOWN);
}

static t_format_type	parse_type(t_flags *value_format, char c, va_list *arg)
{
	const t_format_type	f_type = get_type(c);

	if (f_type & PF_INT)
		value_format->value = (size_t)va_arg(*arg, int);
	else if (f_type & (PF_UINT | PF_HEX_U | PF_HEX_L))
		value_format->value = (size_t)va_arg(*arg, unsigned int);
	else if (f_type & PF_ADR)
		value_format->value = (size_t)va_arg(*arg, void *);
	else if (f_type & PF_STR)
		value_format->value = (size_t)va_arg(*arg, char *);
	else if (f_type & PF_SYM)
		value_format->value = (size_t)(unsigned char)va_arg(*arg, int);
	else if (f_type == PF_UNKNOWN)
	{
		value_format->value = (size_t)(c);
		return (PF_SYM);
	}
	return (f_type);
}

static int				parse_num_value(const char *str,
							size_t *i, va_list *args)
{
	unsigned int	num_value;

	if (str[*i] == '*')
		return (va_arg(*args, int));
	num_value = ft_atoi(&str[*i]);
	while (ft_isdigit(str[*i]))
		*i += 1;
	*i -= 1;
	return (num_value);
}

static t_flags			empty_format_flags(void)
{
	return ((t_flags){
		.value = 0,
		.width = 0,
		.precision_value = 0,
		.type = PF_UNKNOWN,
		.alignment = PF_ALIGN_RIGHT,
		.zero_filling = 0,
		.precision = 0
	});
}

t_flags					parse_format_flags(const char *str,
							size_t *i, va_list *args)
{
	t_flags		value_format;

	value_format = empty_format_flags();
	while (1)
	{
		if (str[*i] == '-')
			value_format.alignment = PF_ALIGN_LEFT;
		else if (str[*i] == '.' && (value_format.precision = 1))
		{
			if ((ft_isdigit(str[*i + 1]) || str[*i + 1] == '*') && (*i += 1))
				value_format.precision_value = parse_num_value(str, i, args);
		}
		else if (str[*i] == '0')
			value_format.zero_filling = 1;
		else if (ft_isdigit(str[*i]) || str[*i] == '*')
			value_format.width = parse_num_value(str, i, args);
		else
			break ;
		*i += 1;
	}
	if (value_format.width < 0 && (value_format.alignment = PF_ALIGN_LEFT))
		value_format.width = -value_format.width;
	value_format.type = parse_type(&value_format, str[*i], args);
	*i += 1;
	return (value_format);
}
