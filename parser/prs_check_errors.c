/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_err_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:59:21 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/26 23:08:15 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_printf.h"

static bool			check_prev(t_node *tk_list, enum e_token allow_mask)
{
	struct s_token	*tk;

	tk_list = tk_list->prev ? tk_list->prev : tk_list;
	tk = tk_list->content;
	return ((tk->type & allow_mask) != 0);
}

static bool			check_next(t_node *tk_list, enum e_token allow_mask)
{
	struct s_token	*tk;

	tk_list = tk_list->next ? tk_list->next : tk_list;
	tk = tk_list->content;
	return ((tk->type & allow_mask) != 0);
}

void				prs_check_errors(t_node *tk_list)
{
	struct s_token	*tk;
	bool			check;

	while (tk_list)
	{
		tk = tk_list->content;
		if (tk->type == TK_PIPE)
		{
			check = check_prev(tk_list, (TK_WORD | TK_FNAME));
			check &= check_next(tk_list, (TK_WORD | TK_RDRS));
			if (!check)
				ft_printf(2, "ERROR\n");
		}
		else if (tk->type & TK_RDRS)
		{
			check = check_next(tk_list, TK_FNAME);
			if (!check)
				ft_printf(2, "ERROR\n");
		}
		tk_list = tk_list->next;
	}
}
