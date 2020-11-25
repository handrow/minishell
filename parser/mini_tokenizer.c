/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:19:36 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/25 17:20:55 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

void					token_free(void *tk_addr)
{
	const struct s_token *tk = tk_addr;

	free(tk->var);
	free((void *)tk);
}

t_node					*tokenize_var(char *var)
{
	struct s_fsm_state	stt;
	int					func_idx;

	struct_state_init(&stt, var);
	while (stt.run == true)
	{
		func_idx = 0;
		while (func_idx < MFSM_HANDLERS_NUM)
		{
			if (g_mfsm_filters[func_idx](&stt) == true)
			{
				g_mfsm_handlers[func_idx](&stt);
				break ;
			}
			func_idx += 1;
		}
		if (func_idx == MFSM_HANDLERS_NUM)
			stt_default_handler(&stt);
	}
	return (stt.tk_list);
}
