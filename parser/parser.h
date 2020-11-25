/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:55:49 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/25 19:22:08 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "tokenizer.h"
# include "env_var.h"

# define MFSM_HANDLERS_NUM 4

extern t_fsm_filter_func g_mfsm_filters[];
extern t_fsm_handler_func g_mfsm_handlers[];

void			token_free(void *tk_addr);

void			derefernce_vars(t_node **tk_list, t_env_containter env);
t_node			*tokenize_var(char *var);
void			wordjoin(t_node *tk_list);

#endif
