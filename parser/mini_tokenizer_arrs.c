/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenizer_arrs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:15:01 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/25 17:28:34 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_fsm_filter_func g_mfsm_filters[MFSM_HANDLERS_NUM] = {
	fsm_filter_space,
	fsm_filter_word,
	fsm_filter_end,
	fsm_filter_none,
};

t_fsm_handler_func g_mfsm_handlers[MFSM_HANDLERS_NUM] = {
	fsm_hndl_space,
	fsm_hndl_word,
	fsm_hndl_end,
	fsm_hndl_none,
};
