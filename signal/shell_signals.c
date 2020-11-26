/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:19:51 by handrow           #+#    #+#             */
/*   Updated: 2020/11/26 18:39:49 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_signals.h"
#include <signal.h>

bool	g_sigint = false;
bool	g_sigquit = false;

static void	sig_flags(int signum)
{
	if (signum == SIGINT)
		g_sigint = true;
	else if (signum == SIGQUIT)
		g_sigquit = true;
}

void		sig_set(void)
{
	signal(SIGINT, sig_flags);
	signal(SIGQUIT, sig_flags);
}

void		sig_reset(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
