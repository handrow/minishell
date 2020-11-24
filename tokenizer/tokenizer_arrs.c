/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_arrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:15:01 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/24 18:46:40 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_fsm_filter_func g_fsm_filters[FSM_HANDLERS_NUM] = {
	fsm_filter_var_end,
	fsm_filter_space,
	fsm_filter_comma,
	fsm_filter_pipe,
	fsm_filter_squote,
	fsm_filter_dquote,
	fsm_filter_word,
	fsm_filter_var,
	fsm_filter_rdrs,
	fsm_filter_end,
	fsm_filter_none,
};

t_fsm_handler_func g_fsm_handlers[FSM_HANDLERS_NUM] = {
	fsm_hndl_var_end,
	fsm_hndl_space,
	fsm_hndl_comma,
	fsm_hndl_pipe,
	fsm_hndl_squote,
	fsm_hndl_dquote,
	fsm_hndl_word,
	fsm_hndl_var,
	fsm_hndl_rdrs,
	fsm_hndl_end,
	fsm_hndl_none,
};

t_fsm_tkn_func g_fsm_tkn_funcs[] = {
	tkn_add_none,
	tkn_add_word,
	tkn_add_space,
	tkn_add_comma,
	tkn_add_pipe,
	tkn_add_word,
	tkn_add_word,
	tkn_add_var,
	tkn_add_var
};
