/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_make_tkn_group.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:07:17 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/30 01:40:01 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_printf.h"
#include "err_msg.h"

static t_node			*err_exit(t_node **root)
{
	err_msg("syntax error", "command is empty");
	dlst_del(root, token_free);
	return (NULL);
}

static bool				check_cmds(t_node *tk_list)
{
	bool			is_cmd;
	struct s_token	*tk;

	while (tk_list)
	{
		is_cmd = false;
		while (tk_list && (tk = tk_list->content) && tk->type != TK_COMMA)
		{
			is_cmd |= tk->type != TK_SP;
			tk_list = tk_list->next;
		}
		if (tk->type == TK_COMMA)
			tk_list = tk_list->next;
		else
			is_cmd = true;
		if (!is_cmd)
			break ;
	}
	return (is_cmd);
}

t_node					*prs_extract_token_group(t_node **tk_list)
{
	struct s_token	*tk;
	t_node *const	root = *tk_list;
	t_node			*tmp;

	if (!(check_cmds(*tk_list)))
		return (err_exit(tk_list));
	while ((*tk_list) && (tk = (*tk_list)->content) && tk->type != TK_COMMA)
		*tk_list = (*tk_list)->next;
	if ((*tk_list) && tk->type == TK_COMMA)
	{
		tmp = *tk_list;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		*tk_list = (*tk_list)->next;
		dlst_del_elem((t_node **)&root, tmp, token_free);
	}
	return (root);
}
