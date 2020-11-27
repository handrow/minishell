/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:35:45 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 00:00:30 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"
#include "err_msg.h"
#include "ft_printf.h"
#include "unistd.h"

int	blt_env(char **argv, t_env_containter *env)
{
	t_node				*it;
	struct s_env_var	*var;

	it = *env;
	if (argv[1] != NULL)
	{
		err_msg("env", "too many arguments");
		return (1);
	}
	else
	{
		while (it)
		{
			var = it->content;
			ft_printf(STDOUT_FILENO, "%s=%s\n", var->key, var->value);
			it = it->next;
		}
	}
	return (0);
}
