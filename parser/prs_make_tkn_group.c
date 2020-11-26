/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_make_tkn_group.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:07:17 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/26 23:34:34 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_printf.h"

t_node			*prs_extract_token_group(t_node **tk_list)
{
	struct s_token	*tk;
	t_node			*root;
	t_node			*tmp;
	bool			is_cmd;

	root = *tk_list;
	is_cmd = false;
	while ((*tk_list) && (tk = (*tk_list)->content) && tk->type != TK_COMMA)
	{
		is_cmd |= tk->type != TK_SP;
		*tk_list = (*tk_list)->next;
	}
	if ((*tk_list) && tk->type == TK_COMMA)
	{
		tmp = *tk_list;
		if (!(tmp->prev) || is_cmd == false)
			ft_printf(2, "Error\n");
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		*tk_list = (*tk_list)->next;
		dlst_del_elem(&root, tmp, token_free);
	}
	return (root);
}
