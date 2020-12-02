/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_get_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 04:04:37 by handrow           #+#    #+#             */
/*   Updated: 2020/12/02 06:17:03 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_opts.h"
#include "builtins.h"
#include "libft.h"

t_builtin_func	blt_get_func(const char *name)
{
	const bool elista_version = !*opts_opt(CMD_NOT_ELISTA_EDITION_FL);

	if (name == NULL)
		return (blt_dummy);
	else if (ft_strcmp("exit", name) == 0)
		return (blt_exit);
	else if (ft_strcmp("env", name) == 0)
		return (blt_env);
	else if (ft_strcmp("export", name) == 0)
		return (elista_version ? blt_elista_export : blt_export);
	else if (ft_strcmp("unset", name) == 0)
		return (blt_unset);
	else if (ft_strcmp("echo", name) == 0)
		return (blt_echo);
	else if (ft_strcmp("cd", name) == 0)
		return (blt_cd);
	else if (ft_strcmp("pwd", name) == 0)
		return (blt_pwd);
	return (NULL);
}
