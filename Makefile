# **************************************************************************** #
# GENERIC_VARIABLES

OBJ_DIR = build

# **************************************************************************** #
# COMPILER_OPTIONS

C_COMPILER = clang
C_STANDART = -std=c99
C_CFLAGS =  $(CFLAGS) $(CPPFLAGS) -Wall -Wextra
C_LFLAGS =  $(CFLAGS) $(CPPFLAGS) -Wall -Wextra

# **************************************************************************** #
# BUILTINS TARGET DESCRIPTION

BUILTINS_NAME = builtins
BUILTINS_PATH = builtins
BUILTINS_FILE = builtins/libbuiltins.a
BUILTINS_SRCS = blt_get_func.c blt_dummy.c
BUILTINS_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(BUILTINS_SRCS))
BUILTINS_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(BUILTINS_SRCS))
BUILTINS_LIBS = 
BUILTINS_INCS = -I env_var -I libft

# **************************************************************************** #
# TOKENIZER TARGET DESCRIPTION

TOKENIZER_NAME = tokenizer
TOKENIZER_PATH = tokenizer
TOKENIZER_FILE = tokenizer/libtokenizer.a
TOKENIZER_SRCS = tokenizer_comma.c tokenizer_word.c tokenizer_space.c tokenizer_pipe.c tokenizer_dquote.c tokenizer_var.c tokenizer_rdrs.c tokenizer_end.c tokenizer_squote.c tokenizer_arrs.c tokenizer.c
TOKENIZER_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(TOKENIZER_SRCS))
TOKENIZER_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(TOKENIZER_SRCS))
TOKENIZER_LIBS = 
TOKENIZER_INCS = -I tokenizer -I libft

# **************************************************************************** #
# EXECUTOR TARGET DESCRIPTION

EXECUTOR_NAME = executor
EXECUTOR_PATH = executor
EXECUTOR_FILE = executor/libexecutor.a
EXECUTOR_SRCS = executor.c forky_utils.c forky_builtin_rdr.c redirection.c forky_binary.c forky_builtin.c executor_utils.c
EXECUTOR_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(EXECUTOR_SRCS))
EXECUTOR_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(EXECUTOR_SRCS))
EXECUTOR_LIBS = 
EXECUTOR_INCS = -I libft -I env_var -I builtins -I ft_printf -I errors -I .

# **************************************************************************** #
# TEST_EXEC_1.OUT TARGET DESCRIPTION

TEST_EXEC_1.OUT_NAME = test_exec_1.out
TEST_EXEC_1.OUT_PATH = tests
TEST_EXEC_1.OUT_FILE = tests/test_exec_1.out
TEST_EXEC_1.OUT_SRCS = executor_1.c
TEST_EXEC_1.OUT_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(TEST_EXEC_1.OUT_SRCS))
TEST_EXEC_1.OUT_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(TEST_EXEC_1.OUT_SRCS))
TEST_EXEC_1.OUT_LIBS = -l executor -L executor -l readline -L readline -l builtins -L builtins -l err-minishell -L errors -l printf -L ft_printf -l tokenizer -L tokenizer -l env-var -L env_var -l ft -L libft
TEST_EXEC_1.OUT_INCS = -I errors -I libft -I env_var -I builtins -I readline -I executor -I ft_printf

# **************************************************************************** #
# ERR-MINISHELL TARGET DESCRIPTION

ERR-MINISHELL_NAME = err-minishell
ERR-MINISHELL_PATH = errors
ERR-MINISHELL_FILE = errors/liberr-minishell.a
ERR-MINISHELL_SRCS = err_msg.c
ERR-MINISHELL_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(ERR-MINISHELL_SRCS))
ERR-MINISHELL_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(ERR-MINISHELL_SRCS))
ERR-MINISHELL_LIBS = 
ERR-MINISHELL_INCS = -I ft_printf

# **************************************************************************** #
# ENV-VAR TARGET DESCRIPTION

ENV-VAR_NAME = env-var
ENV-VAR_PATH = env_var
ENV-VAR_FILE = env_var/libenv-var.a
ENV-VAR_SRCS = env_path.c env_get_set.c env_rm.c env_import_export.c
ENV-VAR_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(ENV-VAR_SRCS))
ENV-VAR_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(ENV-VAR_SRCS))
ENV-VAR_LIBS = 
ENV-VAR_INCS = -I env_var -I libft

# **************************************************************************** #
# PRINTF TARGET DESCRIPTION

PRINTF_NAME = printf
PRINTF_PATH = ft_printf
PRINTF_FILE = ft_printf/libprintf.a
PRINTF_SRCS = print_utils.c ft_printf.c print_values.c parse.c
PRINTF_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(PRINTF_SRCS))
PRINTF_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(PRINTF_SRCS))
PRINTF_LIBS = 
PRINTF_INCS = -I libft -I ft_printf

# **************************************************************************** #
# MINISHELL TARGET DESCRIPTION

MINISHELL_NAME = minishell
MINISHELL_PATH = .
MINISHELL_FILE = ./minishell
MINISHELL_SRCS = main.c
MINISHELL_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(MINISHELL_SRCS))
MINISHELL_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(MINISHELL_SRCS))
MINISHELL_LIBS = -l executor -L executor -l readline -L readline -l builtins -L builtins -l printf -L ft_printf -l tokenizer -L tokenizer -l env-var -L env_var -l ft -L libft
MINISHELL_INCS = -I tokenizer -I libft -I env_var -I builtins -I readline -I executor -I ft_printf -I .

# **************************************************************************** #
# FT TARGET DESCRIPTION

FT_NAME = ft
FT_PATH = libft
FT_FILE = libft/libft.a
FT_SRCS = ft_strnstr.c ft_isdigit.c ft_putstr_fd.c dlst_elem.c dlst_push_back.c ft_strlcpy.c ft_strlen.c ft_memcmp.c ft_putnbr_fd.c ft_strchr.c ft_bzero.c ft_strjoin.c ft_isascii.c ft_memcpy.c get_next_line.c ft_memccpy.c ft_isprint.c dlst_insert.c dlst_pop_back.c ft_putendl_fd.c ft_toupper.c ft_split.c dlst_push_front.c ft_strrchr.c dlst_del.c dlst_size.c ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_memset.c ft_substr.c ft_strncmp.c dlst_del_elem.c ft_strmapi.c ft_strtrim.c ft_memmove.c ft_strlcat.c ft_calloc.c ft_strdup.c dlst_pop_front.c ft_atoi.c ft_isalnum.c ft_itoa.c ft_tolower.c ft_strcmp.c
FT_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(FT_SRCS))
FT_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(FT_SRCS))
FT_LIBS = 
FT_INCS = -I libft

# **************************************************************************** #
# READLINE TARGET DESCRIPTION

READLINE_NAME = readline
READLINE_PATH = readline
READLINE_FILE = readline/libreadline.a
READLINE_SRCS = readline_utils.c readline.c
READLINE_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(READLINE_SRCS))
READLINE_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(READLINE_SRCS))
READLINE_LIBS = 
READLINE_INCS = -I readline -I libft

# **************************************************************************** #
# TEST_TOKEN_1.OUT TARGET DESCRIPTION

TEST_TOKEN_1.OUT_NAME = test_token_1.out
TEST_TOKEN_1.OUT_PATH = tests
TEST_TOKEN_1.OUT_FILE = tests/test_token_1.out
TEST_TOKEN_1.OUT_SRCS = tokenizer_1.c
TEST_TOKEN_1.OUT_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(TEST_TOKEN_1.OUT_SRCS))
TEST_TOKEN_1.OUT_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(TEST_TOKEN_1.OUT_SRCS))
TEST_TOKEN_1.OUT_LIBS = -l executor -L executor -l readline -L readline -l builtins -L builtins -l err-minishell -L errors -l printf -L ft_printf -l tokenizer -L tokenizer -l env-var -L env_var -l ft -L libft
TEST_TOKEN_1.OUT_INCS = -I errors -I tokenizer -I libft -I env_var -I builtins -I readline -I executor -I ft_printf -I .

# **************************************************************************** #
# GENERIC RULES

.PHONY: all re clean fclean
.DEFAULT_GOAL = all

all: $(BUILTINS_FILE) $(TOKENIZER_FILE) $(EXECUTOR_FILE) $(ERR-MINISHELL_FILE) $(ENV-VAR_FILE) $(PRINTF_FILE) $(FT_FILE) $(READLINE_FILE) $(TEST_EXEC_1.OUT_FILE) $(MINISHELL_FILE) $(TEST_TOKEN_1.OUT_FILE)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(BUILTINS_FILE) $(TOKENIZER_FILE) $(EXECUTOR_FILE) $(ERR-MINISHELL_FILE) $(ENV-VAR_FILE) $(PRINTF_FILE) $(FT_FILE) $(READLINE_FILE) $(TEST_EXEC_1.OUT_FILE) $(MINISHELL_FILE) $(TEST_TOKEN_1.OUT_FILE)

re: fclean all

$(BUILTINS_FILE): $(BUILTINS_OBJS)
	@ar rc $(BUILTINS_FILE) $(BUILTINS_OBJS)
	@ranlib $(BUILTINS_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(BUILTINS_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(BUILTINS_INCS) -o $@ -c $< -MMD

$(TOKENIZER_FILE): $(TOKENIZER_OBJS)
	@ar rc $(TOKENIZER_FILE) $(TOKENIZER_OBJS)
	@ranlib $(TOKENIZER_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(TOKENIZER_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(TOKENIZER_INCS) -o $@ -c $< -MMD

$(EXECUTOR_FILE): $(EXECUTOR_OBJS)
	@ar rc $(EXECUTOR_FILE) $(EXECUTOR_OBJS)
	@ranlib $(EXECUTOR_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(EXECUTOR_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(EXECUTOR_INCS) -o $@ -c $< -MMD

$(TEST_EXEC_1.OUT_FILE): $(EXECUTOR_FILE) $(READLINE_FILE) $(BUILTINS_FILE) $(ERR-MINISHELL_FILE) $(PRINTF_FILE) $(TOKENIZER_FILE) $(ENV-VAR_FILE) $(FT_FILE) $(TEST_EXEC_1.OUT_OBJS)
	@$(C_COMPILER) $(C_LFLAGS) $(C_STANDART) -o $(TEST_EXEC_1.OUT_FILE) $(TEST_EXEC_1.OUT_OBJS)  $(TEST_EXEC_1.OUT_LIBS)
	@printf 'Finished	\033[1;32m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(TEST_EXEC_1.OUT_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(TEST_EXEC_1.OUT_INCS) -o $@ -c $< -MMD

$(ERR-MINISHELL_FILE): $(ERR-MINISHELL_OBJS)
	@ar rc $(ERR-MINISHELL_FILE) $(ERR-MINISHELL_OBJS)
	@ranlib $(ERR-MINISHELL_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(ERR-MINISHELL_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(ERR-MINISHELL_INCS) -o $@ -c $< -MMD

$(ENV-VAR_FILE): $(ENV-VAR_OBJS)
	@ar rc $(ENV-VAR_FILE) $(ENV-VAR_OBJS)
	@ranlib $(ENV-VAR_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(ENV-VAR_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(ENV-VAR_INCS) -o $@ -c $< -MMD

$(PRINTF_FILE): $(PRINTF_OBJS)
	@ar rc $(PRINTF_FILE) $(PRINTF_OBJS)
	@ranlib $(PRINTF_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(PRINTF_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(PRINTF_INCS) -o $@ -c $< -MMD

$(MINISHELL_FILE): $(EXECUTOR_FILE) $(READLINE_FILE) $(BUILTINS_FILE) $(PRINTF_FILE) $(TOKENIZER_FILE) $(ENV-VAR_FILE) $(FT_FILE) $(MINISHELL_OBJS)
	@$(C_COMPILER) $(C_LFLAGS) $(C_STANDART) -o $(MINISHELL_FILE) $(MINISHELL_OBJS)  $(MINISHELL_LIBS)
	@printf 'Finished	\033[1;32m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(MINISHELL_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(MINISHELL_INCS) -o $@ -c $< -MMD

$(FT_FILE): $(FT_OBJS)
	@ar rc $(FT_FILE) $(FT_OBJS)
	@ranlib $(FT_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(FT_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(FT_INCS) -o $@ -c $< -MMD

$(READLINE_FILE): $(READLINE_OBJS)
	@ar rc $(READLINE_FILE) $(READLINE_OBJS)
	@ranlib $(READLINE_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(READLINE_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(READLINE_INCS) -o $@ -c $< -MMD

$(TEST_TOKEN_1.OUT_FILE): $(EXECUTOR_FILE) $(READLINE_FILE) $(BUILTINS_FILE) $(ERR-MINISHELL_FILE) $(PRINTF_FILE) $(TOKENIZER_FILE) $(ENV-VAR_FILE) $(FT_FILE) $(TEST_TOKEN_1.OUT_OBJS)
	@$(C_COMPILER) $(C_LFLAGS) $(C_STANDART) -o $(TEST_TOKEN_1.OUT_FILE) $(TEST_TOKEN_1.OUT_OBJS)  $(TEST_TOKEN_1.OUT_LIBS)
	@printf 'Finished	\033[1;32m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(TEST_TOKEN_1.OUT_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(TEST_TOKEN_1.OUT_INCS) -o $@ -c $< -MMD

-include $(BUILTINS_DEPS) $(TOKENIZER_DEPS) $(EXECUTOR_DEPS) $(TEST_EXEC_1.OUT_DEPS) $(ERR-MINISHELL_DEPS) $(ENV-VAR_DEPS) $(PRINTF_DEPS) $(MINISHELL_DEPS) $(FT_DEPS) $(READLINE_DEPS) $(TEST_TOKEN_1.OUT_DEPS)
