/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_opts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 04:01:50 by handrow           #+#    #+#             */
/*   Updated: 2020/12/02 06:22:54 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_opts.h"
#include "err_msg.h"
#include "libft.h"

static const char	*g_opts_keys[CMD_OPTS_SIZE] =
{
	CMD_NOT_ELISTA_EDITION_FL, CMD_POSIX_FORMAT_FL
};

static bool			g_opts_vals[CMD_OPTS_SIZE] =
{
	false, false
};

bool				*opts_opt(const char *opt_name)
{
	int		i;

	i = 0;
	while (i < CMD_OPTS_SIZE)
	{
		if (ft_strcmp(g_opts_keys[i], opt_name) == 0)
			return (g_opts_vals + i);
		++i;
	}
	return (NULL);
}

void				opts_parse(char *av[])
{
	char	*arg;
	int		i;
	bool	*opt_val;

	while (*(++av) != NULL)
	{
		arg = *av;
		if (arg[0] == '-' && arg[1] != '\0')
		{
			++arg;
			i = 0;
			while (i < CMD_OPTS_SIZE)
			{
				opt_val = opts_opt(arg);
				if (opt_val != NULL)
					*opt_val = true;
				else
					err_msg_n_exit(2, "unkonw option", arg);
				++i;
			}
		}
	}
}
