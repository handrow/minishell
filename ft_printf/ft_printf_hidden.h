/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hidden.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:09:34 by handrow           #+#    #+#             */
/*   Updated: 2020/11/21 15:24:30 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_HIDDEN_H
# define PRINTF_HIDDEN_H

# include "libft.h"
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putch_n(int fd, char c, int n);
int		ft_putstr_n(int fd, const char *str, int n);
int		ft_digit_len(unsigned long long num, int base);
int		ft_putnbr(int fd, unsigned long long n, int base, int upper_case);


typedef enum		e_format_type
{
	PF_UNKNOWN = 0,
	PF_INT = 0b1,
	PF_UINT = 0b10,
	PF_HEX_L = 0b100,
	PF_HEX_U = 0b1000,
	PF_ADR = 0b10000,
	PF_SYM = 0b100000,
	PF_STR = 0b1000000
}					t_format_type;

typedef enum		e_format_align
{
	PF_ALIGN_RIGHT = 0,
	PF_ALIGN_LEFT = 1
}					t_format_align;

typedef struct		s_flags
{
	size_t			value;
	int				width;
	int				precision_value;
	t_format_type	type;
	t_format_align	alignment;
	unsigned char	zero_filling;
	unsigned char	precision;
}					t_flags;

t_flags				parse_format_flags(const char *str, size_t *i,
					va_list *args);
int					print_value(int fd, t_flags value_flags);

#endif
