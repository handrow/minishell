/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 07:50:13 by handrow           #+#    #+#             */
/*   Updated: 2020/11/23 21:25:00 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

void	execute_instructions(t_instruction_list cmd, t_env_containter *env)
{
	struct s_forky_info		info;
	struct s_instruction	*instr;
	pid_t					last_pid;
	char					*tmp;
	
	while ((instr = cmd->content))
	{
		info.argv = instr->argv;
		info.rdrs = instr->rdr_list;
		fill_pipes(&info, cmd);
		select_forky(&info);
		last_pid = ((t_forky_func)info.forky_func)(&info, env);
		if (info.ou)
			cmd = cmd->next->next;
		else
			break ;
	}
	if (info.fork_flag)
		info.exit_code = get_last_ec_n_wait(last_pid);
	tmp = ft_itoa(info.exit_code);
	env_set(env, "?", tmp); // check error
	free(tmp);
}
