/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_dquote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:23:53 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/24 17:38:49 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

bool		fsm_filter_dquote(const struct s_fsm_state *stt)
{
	return (stt->in_str[stt->i] == '"' && stt->c_stt != STT_SQ);
}

void		fsm_hndl_dquote(struct s_fsm_state *stt)
{
	g_fsm_tkn_funcs[stt->c_stt](stt);
	stt->c_stt = stt->c_stt == STT_DQ ? STT_NONE : STT_DQ;
	stt->st = ++stt->i;
}
