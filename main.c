/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:32:06 by handrow           #+#    #+#             */
/*   Updated: 2020/12/01 19:16:22 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "err_msg.h"
#include "env_var.h"
#include "readline.h"
#include "tokenizer.h"
#include "shell_signals.h"
#include "instructions.h"
#include "parser.h"
#include "ft_printf.h"
#include "executor.h"

static void		rdl_eof_exit(void)
{
	ft_printf(STDOUT_FILENO, "exit\n");
	exit(0);
}

static char		*readline_activities(void)
{
	int			rdl_status;
	char		*line;

	put_prompt();
	if ((rdl_status = readline(&line)) == 0)
		rdl_eof_exit();
	else if (rdl_status < 0)
		err_system_n_exit(1, NULL);
	return (line);
}

void			run_loop(t_env_containter *env)
{
	char				*cmd;
	t_node				*tk_list;
	t_instruction_list	instr;

	while (true)
	{
		g_state = RSTT_RDL;
		cmd = readline_activities();
		g_state = RSTT_EXECUTIN_SOME_COOL_STAFF_FOR_YA;
		tk_list = tokenize(cmd);
		while (tk_list)
		{
			if (!(prs_check_errors(tk_list)))
				break ;
			if ((instr = parse_tkn_list(*env, &tk_list)))
			{
				execute_instructions(instr, env);
				dlst_del(&instr, instruction_free);
			}
		}
		g_sigint = false;
		free(cmd);
	}
}

int				main(int ac, char **av, const char **ev)
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
