/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:07:38 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/26 22:24:38 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "libft.h"
# include <stdbool.h>

enum					e_fsm_state
{
	STT_NONE,
	STT_W,
	STT_SP,
	STT_COMMA,
	STT_PIPE,
	STT_SQ,
	STT_DQ,
	STT_VAR,
	STT_DVAR
};

struct					s_fsm_state
{
	t_node				*tk_list;
	size_t				st;
	size_t				i;
	char				*in_str;
	enum e_fsm_state	c_stt;
	bool				run;
};

typedef bool			(*t_fsm_filter_func)(const struct s_fsm_state *);
typedef void			(*t_fsm_handler_func)(struct s_fsm_state *);
typedef void			(*t_fsm_tkn_func)(struct s_fsm_state *);

extern t_fsm_filter_func g_fsm_filters[];
extern t_fsm_handler_func g_fsm_handlers[];
extern t_fsm_tkn_func g_fsm_tkn_funcs[];

# define FSM_HANDLERS_NUM 11

enum					e_token
{
	TK_RDR_IN = 0b1,
	TK_RDR_OUT = 0b10,
	TK_RDR_OUT_AP = 0b100,
	TK_WORD = 0b1000,
	TK_SP = 0b10000,
	TK_COMMA = 0b100000,
	TK_PIPE = 0b1000000,
	TK_VAR = 0b10000000,
	TK_DVAR = 0b100000000,
	TK_FNAME = 0b1000000000,
	TK_RDRS = TK_RDR_IN | TK_RDR_OUT | TK_RDR_OUT_AP
};

struct					s_token
{
	enum e_token	type;
	char			*var;
};

t_node					*tokenize(char *cmd);
void					token_free(void *tk_addr);

bool					fsm_filter_word(const struct s_fsm_state *stt);
void					fsm_hndl_word(struct s_fsm_state *stt);
void					tkn_add_word(struct s_fsm_state *stt);

bool					fsm_filter_space(const struct s_fsm_state *stt);
void					fsm_hndl_space(struct s_fsm_state *stt);
void					tkn_add_space(struct s_fsm_state *stt);

bool					fsm_filter_comma(const struct s_fsm_state *stt);
void					fsm_hndl_comma(struct s_fsm_state *stt);
void					tkn_add_comma(struct s_fsm_state *stt);

bool					fsm_filter_pipe(const struct s_fsm_state *stt);
void					fsm_hndl_pipe(struct s_fsm_state *stt);
void					tkn_add_pipe(struct s_fsm_state *stt);

bool					fsm_filter_squote(const struct s_fsm_state *stt);
void					fsm_hndl_squote(struct s_fsm_state *stt);

bool					fsm_filter_dquote(const struct s_fsm_state *stt);
void					fsm_hndl_dquote(struct s_fsm_state *stt);

bool					fsm_filter_var(const struct s_fsm_state *stt);
void					fsm_hndl_var(struct s_fsm_state *stt);
bool					fsm_filter_var_end(const struct s_fsm_state *stt);
void					fsm_hndl_var_end(struct s_fsm_state *stt);
void					tkn_add_var(struct s_fsm_state *stt);

bool					fsm_filter_rdrs(const struct s_fsm_state *stt);
void					fsm_hndl_rdrs(struct s_fsm_state *stt);

bool					fsm_filter_end(const struct s_fsm_state *stt);
void					fsm_hndl_end(struct s_fsm_state *stt);

bool					fsm_filter_none(const struct s_fsm_state *stt);
void					fsm_hndl_none(struct s_fsm_state *stt);
void					tkn_add_none(struct s_fsm_state *stt);

#endif
