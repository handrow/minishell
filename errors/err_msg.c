/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:29:32 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 05:44:17 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void	err_msg(const char *msg, const char *ap)
{
	if (ap)
		ft_printf(STDERR_FILENO, "%s: %s: %s\n", "minishell", msg, ap);
	else
		ft_printf(STDERR_FILENO, "%s: %s\n", "minishell", msg);
}

void	err_system(const char *ap)
{
	err_msg(strerror(errno), ap);
}

void	err_msg_n_exit(int exit_code, const char *msg, const char *ap)
{
	err_msg(msg, ap);
	exit(exit_code);
}

void	err_system_n_exit(int exit_code, const char *ap)
{
	err_system(ap);
	exit(exit_code);
}
