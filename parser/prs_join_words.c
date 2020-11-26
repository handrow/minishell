/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_wordjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:39:31 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/26 22:57:48 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void			push_list(t_node **lst, enum e_token type, void *var)
{
	struct s_token *const tk = malloc(sizeof(struct s_token)); // check error

	tk->type = type;
	tk->var = var;
	dlst_push_back(lst, dlst_elem(tk));
}

t_node				*prs_join_words(t_node *tk_list)
{
	struct s_token	*tk;
	char			*buff;
	t_node			*new_lst;

	buff = NULL;
	new_lst = NULL;
	while (tk_list)
	{
		tk = tk_list->content;
		if (tk->type == TK_WORD)
			buff = ft_strappend(&buff, tk->var); //check error
		else
		{
			if (buff)
				push_list(&new_lst, TK_WORD, buff);
			if (tk->type != TK_SP)
				push_list(&new_lst, tk->type, tk->var);
			buff = NULL;
		}
		tk_list = tk_list->next;
	}
	if (buff)
		push_list(&new_lst, TK_WORD, buff);
	dlst_del(&tk_list, token_free);
	return (new_lst);
}
