/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 03:13:22 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 03:43:42 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"
#include "err_msg.h"
#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdbool.h>

static int	skip_n_activate_flag(char **argv, bool *nflag)
{
	int		i;
	int		j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		if (argv[i][0] == '-' && argv[i][1] != '\0')
		{
			while (argv[i][++j])
			{
				if (argv[i][j] == 'n')
					*nflag = true;
				else
					return (i);
			}
		}
		else
			return (i);
	}
	return (i);
}

int			blt_echo(char **argv, t_env_containter *env)
{
	int		i;
	bool	is_nflag;

	(void)env;
	is_nflag = false;
	i = skip_n_activate_flag(argv, &is_nflag);
	while (argv[i])
	{
		ft_printf(STDOUT_FILENO, "%s%s", argv[i], argv[i + 1] ? " " : "");
		++i;
	}
	if (!is_nflag)
		ft_printf(STDOUT_FILENO, "\n");
	return (0);
}
