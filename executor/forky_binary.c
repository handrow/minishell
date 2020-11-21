/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forky_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 10:13:01 by handrow           #+#    #+#             */
/*   Updated: 2020/11/21 15:31:50 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "forky.h"
#include "ft_printf.h"

static void	frk_child_code(struct s_forky_info *info, t_env_containter *env)
{
	char **const	env_arr = env_export_to_arr(env);
	char *const		path = get_path(info->argv[0], env_get(env, "PATH"));
	
	if (frk_manage_fd(info) < 0)
	{
		perror("minishell");
		exit(EXIT_STATUS_ERROR);
	}
	if (!path)
	{
		ft_printf(STDERR_FILENO, "minishell: command not found: %s\n", info->argv[0]);
		exit(EXIT_STATUS_UNKWN_CMD);
	}
	if (!env_arr)
	{
		ft_printf(STDERR_FILENO, "minishell: allocation failed\n");
		exit(EXIT_STATUS_ERROR);
	}	
	execve(path, info->argv, env_arr);
	perror(path);
	exit(EXIT_STATUS_ERROR);
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
	if (info->in)
		frk_close_pipe(info->in);
	return (cpid);
}
