/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 06:50:06 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 07:38:52 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "builtins.h"
#include <sys/wait.h>
#include "ft_printf.h"
#include "err_msg.h"

void	select_forky(struct s_forky_info *info)
{
	const bool	is_blt = blt_get_func(info->argv[0]) != NULL;

	if (!is_blt)
		info->forky_func = forky_binary;
	else if (info->in != NULL || info->ou != NULL || info->rdrs != NULL)
		info->forky_func = forky_builtin_rd;
	else
		info->forky_func = forky_builtin;
}

void	fill_pipes(struct s_forky_info *info, t_node *cmd)
{
	struct s_instruction	*instr;

	info->in = NULL;
	info->ou = NULL;
	if (cmd->prev != NULL)
	{
		instr = cmd->prev->content;
		if (instr->type == IT_PIPE)
			info->in = instr->pipe;
	}
	if (cmd->next != NULL)
	{
		instr = cmd->next->content;
		if (instr->type == IT_PIPE)
			info->ou = instr->pipe;
	}
}

int		get_last_ec_n_wait(pid_t last_pid)
{
	int		stat_loc;
	int		exit_code;

	if (last_pid > 0)
	{
		waitpid(last_pid, &stat_loc, 0);
		if (WIFEXITED(stat_loc))
			exit_code = WEXITSTATUS(stat_loc);
		else if (WIFSIGNALED(stat_loc))
			exit_code = EXIT_STATUS_SIG_BASE + WTERMSIG(stat_loc);
	}
	else
		exit_code = EXIT_STATUS_ERROR;
	while (wait(&stat_loc) > 0)
		continue ;
	return (exit_code);
}
