#include "libft.h"
#include "dlst.h"
#include "executor.h"
#include "instructions.h"
#include "err_msg.h"

#include <stdio.h>

char *argv_ls[] = {
	"ls", "-l", "/", NULL
};

char *argv_cate[] = {
	"cat", "-e", NULL
};

char *argv_false[] = {
	"false", NULL
};

char *argv_sleep10[] = {
	"sleep", "10", NULL
};

char *argv_dummy[] = {
	"dummy", NULL
};

int		main(void)
{
	t_env_containter env = NULL;

	env_set(&env, "PATH", "/bin");

	t_instruction_list cmd_lst = NULL;
	t_rdr_list cmd1_rdr = NULL;

	struct s_rdr c1_r1 = {
		.type = RDR_OUT,
		.filename = "first.txt"
	};

	struct s_rdr c1_r2 = {
		.type = RDR_IN,
		.filename = "not_existant.txt"
	};

	struct s_rdr c1_r3 = {
		.type = RDR_OUT,
		.filename = "not_secret.txt"
	};

	dlst_push_back(&cmd1_rdr, dlst_elem(&c1_r1));
	dlst_push_back(&cmd1_rdr, dlst_elem(&c1_r2));
	dlst_push_back(&cmd1_rdr, dlst_elem(&c1_r3));

	struct s_instruction cmd1 = {
		.type = IT_CMD,
		.argv = argv_cate,
		.rdr_list = cmd1_rdr
	};

	struct s_instruction pip12 = {
		.type = IT_PIPE
	};

	struct s_instruction cmd2 = {
		.type = IT_CMD,
		.argv = argv_dummy,
		.rdr_list = NULL
	};

	dlst_push_back(&cmd_lst, dlst_elem(&cmd1));
	dlst_push_back(&cmd_lst, dlst_elem(&pip12));
	dlst_push_back(&cmd_lst, dlst_elem(&cmd2));

	execute_instructions(cmd_lst, &env);

	return (0);
}
