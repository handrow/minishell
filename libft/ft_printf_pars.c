/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:17:35 by jiandre           #+#    #+#             */
/*   Updated: 2020/07/23 23:53:15 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				flag_width(const char **s)
{
	int			len;
	int			width;
	const char	*str;

	str = *s;
	len = 0;
	while (!(ft_memchr("%cspdiuxX.", *str, 11)))
	{
		len++;
		str++;
	}
	str = str - len;
	width = ft_atoi(str);
	*s = *s + len;
	return (width);
}

int				flag_withstar(const char **s, va_list args)
{
	if (**s == '*')
	{
		*s = *s + 1;
		return (va_arg(args, int));
	}
	else
		return (flag_width(s));
}

void			m_and_z_flgs(const char **str, t_flags **flgs)
{
	t_flags *flags;

	flags = *flgs;
	if (**str == '0')
	{
		flags->zero = 1;
		(*str)++;
	}
	else if (**str == '-')
	{
		flags->minus = 1;
		(*str)++;
	}
}

const char		*ft_print_pars(va_list args, const char *str, t_flags *flgs)
{
	if (*str == '\0')
		return (str);
	while (*str == '0' || *str == '-')
		m_and_z_flgs(&str, &flgs);
	flgs->width = flag_withstar(&str, args);
	if (flgs->width < 0)
	{
		flgs->width = -flgs->width;
		flgs->minus = 1;
	}
	if (*str == '.' && str++)
	{
		flgs->point = 1;
		flgs->precn = flag_withstar(&str, args);
	}
	if (*str)
		flgs->type = *str++;
	return (str);
}
