/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_comma.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:44:13 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/27 22:45:59 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "err_msg.h"

bool		fsm_filter_comma(const struct s_fsm_state *stt)
{
	const char sym = stt->in_str[stt->i];
	const bool is_com = sym == ';' || sym == '\n';

	return (is_com && stt->c_stt != STT_SQ && stt->c_stt != STT_DQ);
}

void		fsm_hndl_comma(struct s_fsm_state *stt)
{
	g_fsm_tkn_funcs[stt->c_stt](stt);
	tkn_add_comma(stt);
	stt->st = ++stt->i;
	stt->c_stt = STT_NONE;
}

void		tkn_add_comma(struct s_fsm_state *stt)
{
	struct s_token *const tk = malloc(sizeof(struct s_token));

	if (!tk)
		err_system_n_exit(3, NULL);
	tk->type = TK_COMMA;
	tk->var = NULL;
	dlst_push_back(&stt->tk_list, dlst_elem(tk));
}
