/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:19:51 by handrow           #+#    #+#             */
/*   Updated: 2020/11/27 21:44:35 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_signals.h"
#include "readline.h"
#include "ft_printf.h"
#include <signal.h>
#include <unistd.h>

enum e_run_state	g_state = false;
bool				g_sigint = false;

static void			sigint_handler(int signum)
{
	(void)signum;
	if (g_state == RSTT_RDL)
	{
		ft_printf(STDOUT_FILENO, "\n");
		put_prompt();
	}
	g_sigint = true;
}

void				sig_set(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

void				sig_reset(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
