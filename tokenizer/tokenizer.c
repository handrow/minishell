/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:19:36 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/24 18:50:58 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void					tkn_add_none(struct s_fsm_state *stt)
{
	(void)stt;
}

static inline void		stt_default_handler(struct s_fsm_state *stt)
{
	stt->i += 1;
}

static inline void		struct_state_init(struct s_fsm_state *stt, char *cmd)
{
	stt->c_stt = STT_NONE;
	stt->in_str = cmd;
	stt->st = 0;
	stt->i = stt->st;
	stt->run = true;
	stt->tk_list = NULL;
}

t_node					*tokenize(char *cmd)
{
	struct s_fsm_state	stt;
	int					func_idx;

	struct_state_init(&stt, cmd);
	while (stt.run == true)
	{
		func_idx = 0;
		while (func_idx < FSM_HANDLERS_NUM)
		{
			if (g_fsm_filters[func_idx](&stt) == true)
			{
				g_fsm_handlers[func_idx](&stt);
				break ;
			}
			func_idx += 1;
		}
		if (func_idx == FSM_HANDLERS_NUM)
			stt_default_handler(&stt);
	}
	return (stt.tk_list);
}
