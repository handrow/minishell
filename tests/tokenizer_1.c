#include "tokenizer.h"
#include "readline.h"
#include "ft_printf.h"

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
int		main(void)
{
	char			*cmd;
	t_node			*tk_list;
	struct s_token	*token;
	ft_printf(1,"minishell> ");
	while(readline(&cmd))
	{
		tk_list = tokenize(cmd);
		ft_printf(1, "-------------------------\n");
		while(tk_list)
		{
			token = tk_list->content;
			ft_printf(1, "`%-15s` %-10s\n", token->var, enum_to_str(token->type));
			tk_list = tk_list->next;
		}
		ft_printf(1, "-------------------------\n");
		ft_printf(1,"minishell> ");
	}
	return (0);
}