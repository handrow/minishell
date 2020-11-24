/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:28:48 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/24 18:55:26 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

bool		fsm_filter_var(const struct s_fsm_state *stt)
{
	return (stt->in_str[stt->i] == '$' && stt->c_stt != STT_SQ);
}

void		fsm_hndl_var(struct s_fsm_state *stt)
{
	g_fsm_tkn_funcs[stt->c_stt](stt);
	stt->st = ++stt->i;
	stt->c_stt = stt->c_stt == STT_DQ ? STT_DVAR : STT_VAR;
}

bool		fsm_filter_var_end(const struct s_fsm_state *stt)
{
	const bool	var = stt->c_stt == STT_VAR || stt->c_stt == STT_DVAR;

	return (var && !(ft_isalnum(stt->in_str[stt->i])));
}

void		fsm_hndl_var_end(struct s_fsm_state *stt)
{
	g_fsm_tkn_funcs[stt->c_stt](stt);
	stt->c_stt = stt->c_stt == STT_DVAR ? STT_DQ : STT_NONE;
	stt->st = stt->i;
}

void		tkn_add_var(struct s_fsm_state *stt)
{
	struct s_token *const tk = malloc(sizeof(struct s_token)); //check error

	tk->type = stt->c_stt == STT_VAR ? TK_VAR : TK_DVAR;
	tk->var = ft_substr(stt->in_str, stt->st, stt->i - stt->st); //check error
	dlst_push_back(&stt->tk_list, dlst_elem(tk));
}
