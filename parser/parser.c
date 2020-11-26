/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:00:00 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/26 22:59:03 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node			*parse_tkn_list(t_env_containter env, t_node **tk_list)
{
	t_node	*tk_group_list;

	tk_group_list = prs_extract_token_group(tk_list);
	prs_derefernce_vars(&tk_group_list, env);
	tk_group_list = prs_join_words(tk_group_list);
	prs_setup_filenames(tk_group_list);
	prs_check_errors(tk_group_list);
	return (prs_create_instruction_list(&tk_group_list));
}
