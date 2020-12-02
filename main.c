/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:32:06 by handrow           #+#    #+#             */
/*   Updated: 2020/12/02 19:45:19 by jiandre          ###   ########.fr       */
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
#include "cmd_opts.h"
#include "builtins.h"

static void		rdl_eof_exit(t_env_containter *env)
{
	ft_printf(STDOUT_FILENO, "exit\n");
	exit(ft_atoi(env_get(env, "?")));
}

static char		*readline_activities(t_env_containter *env)
{
	int			rdl_status;
	char		*line;

	put_prompt();
	if ((rdl_status = readline(&line)) == 0)
	{
		rdl_eof_exit(env);
	}
	else if (rdl_status < 0)
		err_system_n_exit(1, NULL);
	return (line);
}

static int		parse_and_execute(t_node **tk_list, t_env_containter *env,
				bool *cont)
{
	t_instruction_list	instr;
	int					exit_code;

	if (g_sigint == RSTT_RDL)
		set_exit_code(1, env);
	if (!(prs_check_errors(*tk_list)))
	{
		exit_code = EXIT_STATUS_SYNTAX_ERR;
		*cont = false;
	}
	else if ((instr = parse_tkn_list(*env, tk_list)))
	{
		exit_code = execute_instructions(instr, env);
		dlst_del(&instr, instruction_free);
	}
	else
		exit_code = EXIT_STATUS_SYNTAX_ERR;
	return (exit_code);
}

static void		run_loop(t_env_containter *env)
{
	char				*cmd;
	t_node				*tk_list;
	bool				cont;

	while (true)
	{
		g_state = RSTT_RDL;
		cmd = readline_activities(env);
		g_state = RSTT_EXECUTIN_SOME_COOL_STAFF_FOR_YA;
		tk_list = tokenize(cmd);
		if (!tk_list)
			set_exit_code(EXIT_STATUS_SYNTAX_ERR, env);
		cont = true;
		while (tk_list && cont)
			set_exit_code(parse_and_execute(&tk_list, env, &cont), env);
		g_sigint = false;
		free(cmd);
	}
}

int				main(int ac, char **av, const char **ev)
{
	t_env_containter	env;
	char				*pwd;

	env = NULL;
	(void)ac;
	g_state = RSTT_INIT;
	sig_set();
	opts_parse(av);
	put_greetings();
	env_import_from_arr(&env, ev);
	if (*opts_opt(CMD_NOT_ELISTA_EDITION_FL) != true)
		env_set(&env, "OLDPWD", NULL);
	pwd = get_pwd();
	env_set(&env, "PWD", pwd);
	env_set(&env, "SHELL", "minishell");
	free(pwd);
	set_exit_code(0, &env);
	run_loop(&env);
	env_rm_rf(&env);
	return (0);
}
