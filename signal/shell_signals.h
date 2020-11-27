/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:17:03 by handrow           #+#    #+#             */
/*   Updated: 2020/11/27 21:41:26 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_SIGNALS_H
# define SHELL_SIGNALS_H

# include <stdbool.h>

enum						e_run_state
{
	RSTT_INIT,
	RSTT_RDL,
	RSTT_TKN,
	RSTT_PRS,
	RSTT_EXECUTE_SOME_INSTRUCTIONS_WHICH_WAS_SENDED_BY_PARSER,
};

extern bool					g_sigint;
extern enum e_run_state		g_state;

void						sig_set(void);
void						sig_reset(void);

#endif
