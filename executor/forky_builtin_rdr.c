/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forky_builtin_rdr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 10:13:01 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 07:38:35 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "forky.h"
#include "builtins.h"
#include "err_msg.h"
#include "shell_signals.h"

static void	frk_child_code(struct s_forky_info *info, t_env_containter *env)
{
	sig_reset();
	if (frk_manage_fd(info) < 0)
		err_system_n_exit(EXIT_STATUS_ERROR, NULL);
	exit(blt_get_func(info->argv[0])(info->argv, env));
}

pid_t		forky_builtin_rd(struct s_forky_info *info, t_env_containter *env)
{
	pid_t	cpid;

	info->fork_flag = true;
	if (info->ou)
		pipe(info->ou);
	cpid = fork();
	if (cpid == 0)
		frk_child_code(info, env);
	else if (cpid < 0)
		err_system(info->argv[0]);
	if (info->in)
		frk_close_pipe(info->in);
	return (cpid);
}
