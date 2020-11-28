/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 05:28:32 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 05:33:19 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "forky.h"

void				execute_instructions(t_instruction_list cmds,
										t_env_containter *env);
void				select_forky(struct s_forky_info *info);
void				fill_pipes(struct s_forky_info *info, t_node *cmd);
int					get_last_ec_n_wait(pid_t last_pid);

#endif
