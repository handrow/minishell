/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:41:31 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/27 22:48:53 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "err_msg.h"

void		tkn_add_word(struct s_fsm_state *stt)
{
	struct s_token *const tk = malloc(sizeof(struct s_token));

	if (!tk)
		err_system_n_exit(3, NULL);
	tk->type = TK_WORD;
	tk->var = ft_substr(stt->in_str, stt->st, stt->i - stt->st);
	if (!tk->var)
		err_system_n_exit(3, NULL);
	dlst_push_back(&stt->tk_list, dlst_elem(tk));
}

bool		fsm_filter_word(const struct s_fsm_state *stt)
{
	return (stt->in_str[stt->i] != ' ' && stt->c_stt == STT_SP);
}

void		fsm_hndl_word(struct s_fsm_state *stt)
{
	tkn_add_space(stt);
	stt->c_stt = STT_NONE;
	stt->st = stt->i;
}

bool		fsm_filter_none(const struct s_fsm_state *stt)
{
	return (stt->c_stt == STT_NONE);
}

void		fsm_hndl_none(struct s_fsm_state *stt)
{
	stt->c_stt = STT_W;
}
