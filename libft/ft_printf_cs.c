/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 00:32:33 by jiandre           #+#    #+#             */
/*   Updated: 2020/07/22 19:55:59 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_s_point(t_string inp, t_flags flgs)
{
	if ((long)inp.len < flgs.precn || flgs.precn < 0)
		flgs.precn = inp.len;
	if (flgs.width < flgs.precn)
		flgs.width = flgs.precn;
	if (!flgs.minus)
	{
		putsymbs(' ', flgs.width - flgs.precn);
		ft_putstr_fd(inp.str, 1, flgs.precn);
	}
	else
	{
		ft_putstr_fd(inp.str, 1, flgs.precn);
		putsymbs(' ', flgs.width - flgs.precn);
	}
	return (flgs.width);
}

static int		ft_s_nopoint(t_string inp, t_flags flgs)
{
	char space;

	if (flgs.zero)
		space = '0';
	else
		space = ' ';
	if ((long)inp.len < flgs.width)
		flgs.precn = flgs.width - inp.len;
	if (!flgs.minus)
	{
		putsymbs(space, flgs.precn);
		ft_putstr_fd(inp.str, 1, inp.len);
	}
	else
	{
		ft_putstr_fd(inp.str, 1, inp.len);
		putsymbs(space, flgs.precn);
	}
	return (flgs.precn + inp.len);
}

int				ft_printf_s(char *s, t_flags flgs)
{
	t_string	inp;

	inp.str = s;
	if (!inp.str)
		inp.str = "(null)";
	inp.len = ft_strlen(inp.str);
	if (flgs.point)
		return (ft_s_point(inp, flgs));
	else
		return (ft_s_nopoint(inp, flgs));
}

int				printf_c(t_flags flgs, char sym)
{
	char space;

	if (flgs.zero)
		space = '0';
	else
		space = ' ';
	if (!flgs.width)
		flgs.width = 1;
	if (flgs.minus == 1)
	{
		ft_putchar_fd(sym, 1);
		putsymbs(space, flgs.width - 1);
	}
	else
	{
		putsymbs(space, flgs.width - 1);
		ft_putchar_fd(sym, 1);
	}
	return (flgs.width);
}
