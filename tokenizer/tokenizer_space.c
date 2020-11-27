/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:28:22 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/27 22:49:05 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "err_msg.h"

bool		fsm_filter_space(const struct s_fsm_state *stt)
{
	const bool	quote = stt->c_stt != STT_SQ && stt->c_stt != STT_DQ;

	return (stt->in_str[stt->i] == ' ' && stt->c_stt != STT_SP && quote);
}

void		fsm_hndl_space(struct s_fsm_state *stt)
{
	g_fsm_tkn_funcs[stt->c_stt](stt);
	stt->c_stt = STT_SP;
	stt->st = stt->i;
}

void		tkn_add_space(struct s_fsm_state *stt)
{
	struct s_token *const tk = malloc(sizeof(struct s_token));

	if (!tk)
		err_system_n_exit(3, NULL);
	tk->type = TK_SP;
	tk->var = NULL;
	dlst_push_back(&stt->tk_list, dlst_elem(tk));
}
