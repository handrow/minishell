/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:35:53 by jiandre           #+#    #+#             */
/*   Updated: 2020/07/22 19:54:43 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		flg_zero(t_numb *inp)
{
	if (inp->nbr < 0)
	{
		ft_putchar_fd('-', 1);
		inp->nbr = -inp->nbr;
	}
}

static void		flg_zero_p(t_numb *inp, t_flags *flgs)
{
	if (inp->nbr < 0)
	{
		flgs->precn++;
		if (flgs->width < flgs->precn)
			flgs->width++;
	}
}

static int		ft_d_nopoint(t_numb inp, t_flags flgs, int base, int cap)
{
	char space;

	if (flgs.width < 0)
		flgs.width = -flgs.width;
	if (flgs.zero)
	{
		space = '0';
		flg_zero(&inp);
	}
	else
		space = ' ';
	if ((long)inp.len < flgs.width)
		flgs.precn = flgs.width - inp.len;
	if (!flgs.minus)
	{
		putsymbs(space, flgs.precn);
		ft_putnbr_base_fd(inp.nbr, 1, base, cap);
	}
	else
	{
		ft_putnbr_base_fd(inp.nbr, 1, base, cap);
		putsymbs(space, flgs.precn);
	}
	return (flgs.precn + inp.len);
}

static int		ft_d_point(t_numb inp, t_flags flgs, int base, int cap)
{
	if (flgs.precn < 0 && (flgs.zero) && inp.nbr > -1)
		flgs.precn = flgs.width;
	else if (flgs.precn < 0 && (flgs.zero) && inp.nbr < 0)
		flgs.precn = flgs.width - 1;
	if ((long)inp.len <= flgs.precn)
		flg_zero_p(&inp, &flgs);
	if (flgs.precn < (long)inp.len)
		flgs.precn = inp.len;
	if (flgs.width < flgs.precn && flgs.precn > 0)
		flgs.width = flgs.precn;
	if (!flgs.minus)
	{
		putsymbs(' ', flgs.width - flgs.precn);
		flg_zero(&inp);
		putsymbs('0', flgs.precn - inp.len);
		ft_putnbr_base_fd(inp.nbr, 1, base, cap);
	}
	else
	{
		flg_zero(&inp);
		putsymbs('0', flgs.precn - inp.len);
		ft_putnbr_base_fd(inp.nbr, 1, base, cap);
		putsymbs(' ', flgs.width - flgs.precn);
	}
	return (flgs.width);
}

int				printf_diux(t_flags flgs, long nbr, int base, int cap)
{
	t_numb		inp;

	inp.nbr = nbr;
	inp.len = ft_num_len(nbr, base);
	if (!flgs.point)
		return (ft_d_nopoint(inp, flgs, base, cap));
	else
	{
		if (!nbr && !flgs.precn)
		{
			putsymbs(' ', flgs.width);
			return (flgs.width);
		}
		return (ft_d_point(inp, flgs, base, cap));
	}
}
