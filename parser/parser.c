/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:00:00 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/27 23:36:24 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node			*parse_tkn_list(t_env_containter env, t_node **tk_list)
{
	t_node	*tk_group_list;

	tk_group_list = prs_extract_token_group(tk_list);
	if (!tk_group_list)
		return (NULL);
	prs_derefernce_vars(&tk_group_list, env);
	tk_group_list = prs_join_words(tk_group_list);
	prs_setup_filenames(tk_group_list);
	if (!(prs_check_errors(tk_group_list)))
		return (NULL);
	return (prs_create_instruction_list(&tk_group_list));
}
