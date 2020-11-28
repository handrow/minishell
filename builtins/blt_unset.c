/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 01:50:26 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 02:58:48 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"
#include "err_msg.h"
#include "libft.h"
#include <stdbool.h>

static bool	is_var(char *str)
{
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (false);
		++str;
	}
	return (true);
}

static bool	unset_var(char *str, t_env_containter *env)
{
	if (!is_var(str))
		return (false);
	if (env_get(env, str) == NULL)
		return (false);
	env_rm(env, str);
	return (true);
}

int			blt_unset(char **argv, t_env_containter *env)
{
	int	i;
	int	is_err;

	i = 1;
	is_err = 0;
	if (argv[1] == NULL)
		return (0);
	while (argv[i])
	{
		is_err = !unset_var(argv[i], env) || is_err;
		++i;
	}
	return (is_err);
}
