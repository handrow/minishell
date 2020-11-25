/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:55:49 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/26 01:56:00 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "tokenizer.h"
# include "env_var.h"

# define MFSM_HANDLERS_NUM 4

typedef t_node		*t_instruction_list;

extern t_fsm_filter_func g_mfsm_filters[];
extern t_fsm_handler_func g_mfsm_handlers[];

void				token_free(void *tk_addr);

void				derefernce_vars(t_node **tk_list, t_env_containter env);
t_node				*tokenize_var(char *var);
t_node				*wordjoin(t_node *tk_list);
t_instruction_list	make_instruction(t_node *tk_list);

#endif
