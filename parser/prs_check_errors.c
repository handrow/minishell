/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_check_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:59:21 by jiandre           #+#    #+#             */
/*   Updated: 2020/12/01 19:08:33 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_printf.h"
#include "err_msg.h"

static bool			check_prev(t_node *tk_list, enum e_token allow_mask)
{
	struct s_token	*tk;

	tk_list = tk_list->prev ? tk_list->prev : tk_list;
	tk = tk_list->content;
	if (tk->type == TK_SP && tk_list->prev)
		tk = tk_list->prev->content;
	return ((tk->type & allow_mask) != 0);
}

static bool			check_next(t_node *tk_list, enum e_token allow_mask)
{
	struct s_token	*tk;

	tk_list = tk_list->next ? tk_list->next : tk_list;
	tk = tk_list->content;
	if (tk->type == TK_SP && tk_list->next)
		tk = tk_list->next->content;
	return ((tk->type & allow_mask) != 0);
}

static bool			err_exit(enum e_token tk_type, t_node *root)
{
	dlst_del(&root, token_free);
	if (tk_type == TK_PIPE)
		err_msg("syntax error", "no command near |");
	else if (tk_type == TK_RDRS)
		err_msg("syntax error", "no filename");
	return (false);
}

bool				prs_check_errors(t_node *tk_list)
{
	struct s_token	*tk;
	bool			check;
	t_node			*root;

	root = tk_list;
	while (tk_list)
	{
		tk = tk_list->content;
		if (tk->type == TK_PIPE)
		{
			check = check_prev(tk_list, (TK_WORD | TK_FNAME));
			check &= check_next(tk_list, (TK_WORD | TK_RDRS));
			if (!check)
				return (err_exit(TK_PIPE, root));
		}
		else if (tk->type & TK_RDRS)
		{
			check = check_next(tk_list, (TK_WORD | TK_VAR | TK_DVAR));
			if (!check)
				return (err_exit(TK_RDRS, root));
		}
		tk_list = tk_list->next;
	}
	return (true);
}
