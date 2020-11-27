/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:55:49 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/28 01:04:51 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "tokenizer.h"
# include "env_var.h"

# define MFSM_HANDLERS_NUM 4

extern t_fsm_filter_func g_mfsm_filters[];
extern t_fsm_handler_func g_mfsm_handlers[];

t_node				*parse_tkn_list(t_env_containter env, t_node **tk_list);
t_node				*prs_extract_token_group(t_node **tk_list);
void				prs_derefernce_vars(t_node **tk_list, t_env_containter env);
t_node				*tokenize_var(char *var);
t_node				*prs_join_words(t_node *tk_list);
void				prs_setup_filenames(t_node *tk_list);
bool				prs_check_errors(t_node *tk_list);
t_node				*prs_create_instruction_list(t_node **tk_list);

void				instruction_free(void *isntr_addr);
void				rdr_free(void *rdr_addr);

#endif
