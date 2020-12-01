/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forky_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 10:13:01 by handrow           #+#    #+#             */
/*   Updated: 2020/12/01 16:58:16 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "forky.h"
#include "ft_printf.h"
#include "err_msg.h"
#include "shell_signals.h"

static void	frk_child_code(struct s_forky_info *info, t_env_containter *env)
{
	char **const	env_arr = env_export_to_arr(env);
	char *const		path = get_path(info->argv[0], env_get(env, "PATH"));

	sig_reset();
	if (frk_manage_fd(info) < 0)
		err_system_n_exit(EXIT_STATUS_ERROR, NULL);
	if (!path)
		err_msg_n_exit(EXIT_STATUS_UNKWN_CMD,
			"command not found", info->argv[0]);
	if (!env_arr)
		err_system_n_exit(EXIT_STATUS_ERROR, NULL);
	execve(path, info->argv, env_arr);
	err_system_n_exit(EXIT_STATUS_BAD_EXEC, path);
}

pid_t		forky_binary(struct s_forky_info *info, t_env_containter *env)
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
