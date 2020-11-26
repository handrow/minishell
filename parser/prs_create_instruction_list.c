/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_make_instr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:49:40 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/26 23:07:16 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "instructions.h"

static size_t			count_args(t_node *tk_list)
{
	struct s_token	*tk;
	size_t			count;

	count = 0;
	while ((tk_list) && (tk = tk_list->content) && tk->type != TK_PIPE)
	{
		count += tk->type == TK_WORD;
		tk_list = tk_list->next;
	}
	return (count);
}

static t_node			*make_rdr(t_node **tk_list)
{
	t_node					*rdr_node;
	struct s_rdr *const		rdr = malloc(sizeof(struct s_rdr)); //check error
	struct s_token			*tk;

	tk = (*tk_list)->content;
	rdr->type = (enum e_rdr)tk->type;
	(*tk_list) = (*tk_list)->next;
	tk = (*tk_list)->content;
	rdr->filename = ft_strdup(tk->var);
	rdr_node = dlst_elem(rdr); //check error
	return (rdr_node);
}

static t_node			*make_cmd(t_node **tk_list)
{
	struct s_token			*tk;
	struct s_instruction	*instr;
	size_t					i;

	instr = ft_calloc(1, sizeof(struct s_instruction));
	instr->type = IT_CMD;
	instr->argv = ft_calloc(count_args(*tk_list) + 1, sizeof(char *)); //check error
	i = 0;
	while ((*tk_list) && (tk = (*tk_list)->content) && tk->type != TK_PIPE)
	{
		if (tk->type == TK_WORD)
			instr->argv[i++] = ft_strdup(tk->var); //check error
		if (tk->type & TK_RDRS)
			dlst_push_back(&instr->rdr_list, make_rdr(tk_list));
		(*tk_list) = (*tk_list)->next;
	}
	return (dlst_elem(instr));
}

static t_node			*make_pipe(t_node **tk_list)
{
	struct s_instruction	*instr;

	instr = malloc(sizeof(struct s_instruction)); //check error
	instr->type = IT_PIPE;
	instr->rdr_list = NULL;
	instr->argv = NULL;
	*tk_list = (*tk_list)->next;
	return (dlst_elem(instr));
}

t_node					*prs_create_instruction_list(t_node **tk_list)
{
	t_node			*instr_list;
	struct s_token	*tk;
	t_node			*instr;

	instr_list = NULL;
	while (*tk_list)
	{
		tk = (*tk_list)->content;
		instr = (tk->type == TK_PIPE) ? make_pipe(tk_list) : make_cmd(tk_list);
		dlst_push_back(&instr_list, instr);
	}
	dlst_del(tk_list, token_free);
	return (instr_list);
}
