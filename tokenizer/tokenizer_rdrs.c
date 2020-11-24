/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_rdrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:05:13 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/24 19:17:33 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

bool		fsm_filter_rdrs(const struct s_fsm_state *stt)
{
	const char sym = stt->in_str[stt->i];
	const bool is_rdr = sym == '<' || sym == '>';

	return (is_rdr && stt->c_stt != STT_SQ && stt->c_stt != STT_DQ);
}

void		tkn_add_rdr_out_ap(struct s_fsm_state *stt)
{
	struct s_token *const tk = malloc(sizeof(struct s_token)); //check error

	tk->type = TK_RDR_OUT_AP;
	tk->var = NULL;
	dlst_push_back(&stt->tk_list, dlst_elem(tk));
}

void		tkn_add_rdr_out(struct s_fsm_state *stt)
{
	struct s_token *const tk = malloc(sizeof(struct s_token)); //check error

	tk->type = TK_RDR_OUT;
	tk->var = NULL;
	dlst_push_back(&stt->tk_list, dlst_elem(tk));
}

void		tkn_add_rdr_in(struct s_fsm_state *stt)
{
	struct s_token *const tk = malloc(sizeof(struct s_token)); //check error

	tk->type = TK_RDR_IN;
	tk->var = NULL;
	dlst_push_back(&stt->tk_list, dlst_elem(tk));
}

void		fsm_hndl_rdrs(struct s_fsm_state *stt)
{
	const char *tk_str = stt->in_str + stt->i;

	g_fsm_tkn_funcs[stt->c_stt](stt);
	if (tk_str[0] == '>' && tk_str[1] == '>')
	{
		tkn_add_rdr_out_ap(stt);
		stt->i += 2;
	}
	else if (tk_str[0] == '>')
	{
		tkn_add_rdr_out(stt);
		stt->i += 1;
	}
	else
	{
		tkn_add_rdr_in(stt);
		stt->i += 1;
	}
	stt->st = stt->i;
}
