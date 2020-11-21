/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forky_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:32:34 by handrow           #+#    #+#             */
/*   Updated: 2020/11/21 11:35:51 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forky.h"
#include "builtins.h"

pid_t		forky_builtin(struct s_forky_info *info, t_env_containter *env)
{
	info->fork_flag = false;
	info->exit_code = blt_get_func(info->argv[0])(info->argv, env);
	return (0);
}
