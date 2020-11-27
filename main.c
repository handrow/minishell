/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:32:06 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 01:05:42 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env_var.h"
#include "readline.h"
#include "tokenizer.h"
#include "shell_signals.h"
#include "instructions.h"
#include "parser.h"
#include "ft_printf.h"
#include "executor.h"

void	run_loop(t_env_containter *env)
{
	char				*cmd;
	t_node				*tk_list;
	t_instruction_list	instr;

	while (true)
	{
		g_state = RSTT_RDL;
		put_prompt();
		readline(&cmd);
		g_state = RSTT_TKN;
		tk_list = tokenize(cmd);
		while (tk_list)
		{
			g_state = RSTT_PRS;
			if ((instr = parse_tkn_list(*env, &tk_list)))
			{
				g_state = RSTT_EXECUTE_SOME_INSTRUCTIONS_WHICH_WAS_SENDED_BY_PARSER;
				execute_instructions(instr, env);
				dlst_del(&instr, instruction_free);
			}
		}
		g_sigint = false;
		free(cmd);
	}
}

int		main(int ac, char **av, const char **ev)
{
	t_env_containter	env;
	
	env = NULL;
	(void)ac;
	(void)av;
	g_state = RSTT_INIT;
	sig_set();
	env_import_from_arr(&env, ev);
	run_loop(&env);
	env_rm_rf(&env);
	return (0);
}