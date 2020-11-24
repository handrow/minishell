/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:54:23 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/24 14:43:55 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

bool		fsm_filter_end(const struct s_fsm_state *stt)
{
	return (stt->in_str[stt->i] == '\0');
}

void		fsm_hndl_end(struct s_fsm_state *stt)
{
	g_fsm_tkn_funcs[stt->c_stt](stt);
	stt->i += 1;
	stt->run = false;
}
