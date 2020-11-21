/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 05:28:32 by handrow           #+#    #+#             */
/*   Updated: 2020/11/21 09:58:45 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <sys/types.h>
# include <stdbool.h>
# include "instructions.h"
# include "env_var.h"

# define EXIT_STATUS_SIG_BASE 128
# define EXIT_STATUS_UNKWN_CMD 127

typedef pid_t		(*t_forky_func)(struct s_forky_info *, t_env_containter *);
typedef t_node		*t_instruction_list;


struct				s_forky_info
{
	char			**argv;
	t_pipe_ptr		in;
	t_pipe_ptr		ou;
	t_forky_func	forky_func;
	int				exit_code;
	bool			fork_flag;
};

void				execute_instructions(t_instruction_list cmds, t_env_containter *env);
void				select_forky(struct s_forky_info *info);
void				fill_pipes(struct s_forky_info *info, t_node *cmd);
int					get_last_ec_n_wait(pid_t last_pid);

#endif
