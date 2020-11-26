#include "tokenizer.h"
#include "readline.h"
#include "ft_printf.h"
#include "parser.h"
#include "executor.h"
#include <stdio.h>

char 	*enum_to_str(int i)
{
	char *s = NULL;

	if (i == 0b1)
		s = ft_strdup("RDR_IN");
	else if (i == 0b10)
		s = ft_strdup("RDR_OUT");
	else if (i == 0b100)
		s = ft_strdup("RDR_OUT_AP");
	else if (i == 0b1000)
		s = ft_strdup("WORD");
	else if (i == 0b10000)
		s = ft_strdup("SPACE");
	else if (i == 0b100000)
		s = ft_strdup("COMMA");
	else if (i == 0b1000000)
		s = ft_strdup("PIPE");
	else if (i == 0b10000000)
		s = ft_strdup("VAR");
	else if (i == 0b100000000)
		s = ft_strdup("DVAR");
	else if (i == 0b1000000000)
		s = ft_strdup("FNAME");
	return (s);
}

char 	*type_to_str(int i)
{
	char *s = NULL;

	if (i == 0b0)
		s = ft_strdup("CMD");
	else if (i == 0b1)
		s = ft_strdup("PIPE");
	return (s);
}

char 	*rdr_to_str(int i)
{
	char *s = NULL;

	if (i == 0b1)
		s = ft_strdup("RDR_IN");
	else if (i == 0b10)
		s = ft_strdup("RDR_OUT");
	else if (i == 0b100)
		s = ft_strdup("RDR_OUT_AP");
	return (s);
}
void	print_instr(t_node *instr_lst)
{
	struct s_instruction *instr;
	struct s_rdr	*rdr;
	size_t i;
	t_node *rdr_lst;

	while (instr_lst)
	{
		i = 0;
		rdr_lst = NULL;
		instr = instr_lst->content;
		ft_printf(1, "-------------------------\n");
		printf("type: %s\n", type_to_str(instr->type));
		printf("ARGS\n");
		if (instr->argv)
		{
			while(instr->argv[i])
				printf("`%s` ", instr->argv[i++]);
		}
		printf("\nRDRS\n");
		rdr_lst = instr->rdr_list;
		while (rdr_lst)
		{
			rdr = rdr_lst->content;
			printf("\"%s `%s`\"\n", rdr_to_str(rdr->type), rdr->filename);
			rdr_lst = rdr_lst->next;
		}
		ft_printf(1, "-------------------------\n");
		instr_lst = instr_lst->next;
	}
	ft_printf(1, "-----------END-----------\n");
}

// dummy
int		main(int argc, char **argv, const char **envp)
{
	char			*cmd;
	t_node			*tk_list;
	t_env_containter env = NULL;
	struct s_token *token;
	t_instruction_list instr;

	(void)argc;
	(void)argv;
	env_import_from_arr(&env, envp);
	ft_printf(1,"minishell> ");
	while(readline(&cmd))
	{
		tk_list = tokenize(cmd);
		while (tk_list)
		{
			instr = parse_tkn_list(env, &tk_list);
			print_instr(instr);
			ft_printf(1, "-------------------------\n");
			while(tk_list)
			{
				token = tk_list->content;
				ft_printf(1, "%-15s `%s`\n", enum_to_str(token->type), token->var);
				tk_list = tk_list->next;
			}
			ft_printf(1, "-------------------------\n");
		}
		ft_printf(1,"minishell> ");
	}
	return (0);
}