/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:28:48 by jiandre           #+#    #+#             */
/*   Updated: 2020/12/01 17:16:53 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "err_msg.h"

bool		fsm_filter_var(const struct s_fsm_state *stt)
{
	return (stt->in_str[stt->i] == '$' && stt->c_stt != STT_SQ);
}

void		fsm_hndl_var(struct s_fsm_state *stt)
{
	g_fsm_tkn_funcs[stt->c_stt](stt);
	stt->st = ++stt->i;
	if (stt->in_str[stt->i] == '?')
	{
		stt->c_stt = stt->c_stt == STT_DQ ? STT_DVAR : STT_VAR;
		stt->i += 1;
		tkn_add_var(stt);
		stt->c_stt = stt->c_stt == STT_DVAR ? STT_DQ : STT_NONE;
		stt->st = stt->i;
	}
	else
		stt->c_stt = stt->c_stt == STT_DQ ? STT_DVAR : STT_VAR;
}

bool		fsm_filter_var_end(const struct s_fsm_state *stt)
{
	const bool	is_var = (stt->c_stt == STT_VAR || stt->c_stt == STT_DVAR);
	const char	sym = stt->in_str[stt->i];

	return (is_var && !(ft_isalnum(sym)) && sym != '_');
}

void		fsm_hndl_var_end(struct s_fsm_state *stt)
{
	if (stt->st == stt->i)
	{
		--stt->st;
		tkn_add_word(stt);
	}
	else
		g_fsm_tkn_funcs[stt->c_stt](stt);
	stt->c_stt = stt->c_stt == STT_DVAR ? STT_DQ : STT_NONE;
	stt->st = stt->i;
}

void		tkn_add_var(struct s_fsm_state *stt)
{
	struct s_token *const tk = malloc(sizeof(struct s_token));

	if (!tk)
		err_system_n_exit(3, NULL);
	tk->type = stt->c_stt == STT_VAR ? TK_VAR : TK_DVAR;
	tk->var = ft_substr(stt->in_str, stt->st, stt->i - stt->st);
	if (!tk->var)
		err_system_n_exit(3, NULL);
	dlst_push_back(&stt->tk_list, dlst_elem(tk));
}
