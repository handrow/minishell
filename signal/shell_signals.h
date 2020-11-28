/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:17:03 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 06:04:16 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_SIGNALS_H
# define SHELL_SIGNALS_H

# include <stdbool.h>

enum						e_run_state
{
	RSTT_INIT,
	RSTT_RDL,
	RSTT_EXECUTIN_SOME_COOL_STAFF_FOR_YA,
};

extern bool					g_sigint;
extern enum e_run_state		g_state;

void						sig_set(void);
void						sig_reset(void);

#endif
