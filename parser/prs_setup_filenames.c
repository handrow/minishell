/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_setup_filenames.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:46:43 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/26 23:36:53 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void			prs_setup_filenames(t_node *tk_list)
{
	struct s_token	*tk;
	bool			rdr_found;

	rdr_found = false;
	while (tk_list)
	{
		tk = tk_list->content;
		if (rdr_found && tk->type == TK_WORD)
		{
			tk->type = TK_FNAME;
			rdr_found = false;
		}
		if (tk->type & TK_RDRS)
			rdr_found = true;
		tk_list = tk_list->next;
	}
}
