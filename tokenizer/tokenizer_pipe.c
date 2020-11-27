/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:03:39 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/27 22:46:37 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "err_msg.h"

bool		fsm_filter_pipe(const struct s_fsm_state *stt)
{
	const bool	quote = stt->c_stt != STT_SQ && stt->c_stt != STT_DQ;

	return (stt->in_str[stt->i] == '|' && quote);
}

void		fsm_hndl_pipe(struct s_fsm_state *stt)
{
	g_fsm_tkn_funcs[stt->c_stt](stt);
	tkn_add_pipe(stt);
	stt->st = ++stt->i;
	stt->c_stt = STT_NONE;
}

void		tkn_add_pipe(struct s_fsm_state *stt)
{
	struct s_token *const tk = malloc(sizeof(struct s_token));

	if (!tk)
		err_system_n_exit(3, NULL);
	tk->type = TK_PIPE;
	tk->var = NULL;
	dlst_push_back(&stt->tk_list, dlst_elem(tk));
}
