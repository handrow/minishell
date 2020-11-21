/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:44:25 by jiandre           #+#    #+#             */
/*   Updated: 2020/07/22 19:57:00 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_pnull(t_flags flgs)
{
	if (!flgs.width)
		flgs.width = 2;
	if (flgs.precn < 0)
		flgs.precn = 1;
	if (flgs.width < flgs.precn + 2)
		flgs.width = flgs.precn + 2;
	if (flgs.minus == 1)
	{
		ft_putstr_fd("0x", 1, 2);
		putsymbs('0', flgs.precn);
		putsymbs(' ', flgs.width - flgs.precn - 2);
	}
	else
	{
		putsymbs(' ', flgs.width - flgs.precn - 2);
		ft_putstr_fd("0x", 1, 2);
		putsymbs('0', flgs.precn);
	}
	return (flgs.width);
}

static int		ft_d_nopoint(t_numb inp, t_flags flgs, int base)
{
	char space;

	if (flgs.zero)
		space = '0';
	else
		space = ' ';
	if ((long)inp.len + 2 < flgs.width)
		flgs.precn = flgs.width - inp.len - 2;
	if (!flgs.minus)
	{
		putsymbs(space, flgs.precn);
		ft_putstr_fd("0x", 1, 2);
		ft_putnbr_base_fd(inp.nbr, 1, base, 0);
	}
	else
	{
		ft_putstr_fd("0x", 1, 2);
		ft_putnbr_base_fd(inp.nbr, 1, base, 0);
		putsymbs(space, flgs.precn);
	}
	return (flgs.precn + inp.len + 2);
}

static int		ft_d_point(t_numb inp, t_flags flgs, int base)
{
	if (flgs.precn < (long)inp.len || flgs.precn < 0)
		flgs.precn = inp.len;
	if (flgs.width > flgs.precn)
		flgs.width -= 2;
	if (flgs.width < flgs.precn)
		flgs.width = flgs.precn;
	if (!flgs.minus)
	{
		putsymbs(' ', flgs.width - flgs.precn);
		ft_putstr_fd("0x", 1, 2);
		putsymbs('0', flgs.precn - inp.len);
		ft_putnbr_base_fd(inp.nbr, 1, base, 0);
	}
	else
	{
		ft_putstr_fd("0x", 1, 2);
		putsymbs('0', flgs.precn - inp.len);
		ft_putnbr_base_fd(inp.nbr, 1, base, 0);
		putsymbs(' ', flgs.width - flgs.precn);
	}
	return (flgs.width + 2);
}

int				printf_p(t_flags flgs, long nbr, int base)
{
	t_numb		inp;

	inp.nbr = nbr;
	inp.len = ft_num_len(nbr, base);
	if (!flgs.point)
		return (ft_d_nopoint(inp, flgs, base));
	else
	{
		if (nbr == 0)
			return (ft_printf_pnull(flgs));
		return (ft_d_point(inp, flgs, base));
	}
}
