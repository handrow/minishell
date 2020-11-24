/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_squote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:16:15 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/24 17:39:02 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

bool		fsm_filter_squote(const struct s_fsm_state *stt)
{
	return (stt->in_str[stt->i] == '\'' && stt->c_stt != STT_DQ);
}

void		fsm_hndl_squote(struct s_fsm_state *stt)
{
	g_fsm_tkn_funcs[stt->c_stt](stt);
	stt->c_stt = stt->c_stt == STT_SQ ? STT_NONE : STT_SQ;
	stt->st = ++stt->i;
}
