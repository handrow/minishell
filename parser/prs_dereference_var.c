/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_dereference_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:00:10 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/28 03:05:24 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "err_msg.h"

static inline t_node	*dereferense_var_into_list(t_node **tk_list,
						t_node *tmp, t_env_containter env)
{
	struct s_token *const		tk = tmp->content;
	const char					*value = env_get(&env, tk->var);
	t_node						*buff_list;

	if (!value)
	{
		buff_list = *tk_list == tmp ? tmp->next : tmp->prev;
		dlst_del_elem(tk_list, tmp, token_free);
		tmp = buff_list;
	}
	else if (tk->type & TK_DVAR)
	{
		free(tk->var);
		if (!(tk->var = ft_strdup(value)))
			err_system_n_exit(3, NULL);
		tk->type = TK_WORD;
	}
	else if (tk->type & TK_VAR)
	{
		buff_list = tokenize_var((char *)value);
		dlst_insert(tk_list, tmp, buff_list);
		dlst_del_elem(tk_list, tmp, token_free);
		tmp = buff_list;
	}
	return (tmp);
}

void					prs_derefernce_vars(t_node **tk_list,
						t_env_containter env)
{
	struct s_token	*tk;
	t_node			*tmp;

	tmp = *tk_list;
	while (tmp)
	{
		tk = tmp->content;
		if (tk->type & (TK_DVAR | TK_VAR))
			tmp = dereferense_var_into_list(tk_list, tmp, env);
		if (tmp)
			tmp = tmp->next;
	}
}
