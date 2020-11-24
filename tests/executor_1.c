#include "libft.h"
#include "dlst.h"
#include "executor.h"
#include "instructions.h"

#include <stdio.h>

const char *argv_ls[] = {
	"ls", "-l", "/", NULL
};

const char *argv_cate[] = {
	"cat", "-e", NULL
};

const char *argv_false[] = {
	"false", NULL
};

const char *argv_sleep10[] = {
	"sleep", "10", NULL
};

const char *argv_dummy[] = {
	"dummy", NULL
};

// dummy
int		main(void)
{
	t_instruction_list head = NULL;
	t_env_containter env = NULL;
	t_instruction_list rdr = NULL;

	env_set(&env, "PATH", "/bin");

	struct s_instruction cmd1 = { .argv = argv_sleep10, .type = IT_CMD };

	dlst_push_back(&head, dlst_elem(&cmd1));

	execute_instructions(head, &env);

	frk_do_rdr_list(rdr->content);

	return (0);
}
