#include "tokenizer.h"
#include "readline.h"
#include "ft_printf.h"
#include "parser.h"

char 	*enum_to_str(int i)
{
	char *s = NULL;

	if (i == 0)
		s = ft_strdup("WORD");
	else if (i == 1)
		s = ft_strdup("SPACE");
	else if (i == 0b10)
		s = ft_strdup("COMMA");
	else if (i == 0b100)
		s = ft_strdup("PIPE");
	else if (i == 0b1000)
		s = ft_strdup("VAR");
	else if (i == 0b10000)
		s = ft_strdup("DVAR");
	else if (i == 0b100000)
		s = ft_strdup("RDR_IN");
	else if (i == 0b1000000)
		s = ft_strdup("RDR_OUT");
	else if (i == 0b10000000)
		s = ft_strdup("RDR_OUT_AP");
	return (s);
}

// dummy
int		main(int argc, char **argv, const char **envp)
{
	char			*cmd;
	t_node			*tk_list;
	struct s_token	*token;
	t_env_containter env = NULL;

	env_import_from_arr(&env, envp);
	ft_printf(1,"minishell> ");
	while(readline(&cmd))
	{
		tk_list = tokenize(cmd);
		derefernce_vars(&tk_list, env);
		tk_list = wordjoin(tk_list);
		ft_printf(1, "-------------------------\n");
		while(tk_list)
		{
			token = tk_list->content;
			ft_printf(1, "%-15s `%s`\n", enum_to_str(token->type), token->var);
			tk_list = tk_list->next;
		}
		ft_printf(1, "-------------------------\n");
		ft_printf(1,"minishell> ");
	}
	return (0);
}