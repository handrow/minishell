/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:16:56 by handrow           #+#    #+#             */
/*   Updated: 2020/12/02 02:19:37 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include "err_msg.h"
#include "env_var.h"

void	set_exit_code(int exit_code, t_env_containter *env)
{
	char *const		tmp = ft_itoa(exit_code);
	
	if (!tmp)
		err_system_n_exit(1, NULL);
	env_set(env, "?", tmp);
	free(tmp);
}
