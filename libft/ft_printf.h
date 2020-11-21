/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:44:17 by jiandre           #+#    #+#             */
/*   Updated: 2020/08/27 03:32:55 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>

typedef struct		s_flags
{
	char			type;
	long			width;
	long			precn;
	char			zero;
	char			minus;
	char			point;
}					t_flags;

typedef struct		s_string
{
	char			*str;
	size_t			len;
}					t_string;

typedef struct		s_numb
{
	long			nbr;
	size_t			len;
}					t_numb;

int					ft_atoi(const char *ch);
const char			*ft_print_pars(va_list args, const char *str,
					t_flags *flgs);
void				ft_putnbr_base_fd(long n, int fd, size_t base, int cap);
void				putsymbs(int symb, int len);
int					ft_printf_s(char *s, t_flags flgs);
int					printf_c(t_flags flgs, char sym);
int					ft_num_len(long n, int base);
size_t				ft_strlen(const char *s);
void				*ft_memchr(const void *s, int c, size_t n);
int					printf_diux(t_flags flgs, long nbr, int base, int cap);
int					printf_p(t_flags flgs, long nbr, int base);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd, int len);
void				ft_putnbr_fd(long n, int fd);

#endif
