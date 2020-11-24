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
BUILTINS_FILE = build/libbuiltins.a
BUILTINS_SRCS = blt_dummy.c blt_get_func.c
BUILTINS_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(BUILTINS_SRCS))
BUILTINS_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(BUILTINS_SRCS))
BUILTINS_LIBS = 
BUILTINS_INCS = -I env_var -I libft

# **************************************************************************** #
# TOKENIZER TARGET DESCRIPTION

TOKENIZER_NAME = tokenizer
TOKENIZER_PATH = tokenizer
TOKENIZER_FILE = build/libtokenizer.a
TOKENIZER_SRCS = tokenizer_squote.c tokenizer.c tokenizer_dquote.c tokenizer_pipe.c tokenizer_comma.c tokenizer_var.c tokenizer_space.c tokenizer_rdrs.c tokenizer_arrs.c tokenizer_end.c tokenizer_word.c
TOKENIZER_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(TOKENIZER_SRCS))
TOKENIZER_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(TOKENIZER_SRCS))
TOKENIZER_LIBS = 
TOKENIZER_INCS = -I tokenizer -I libft

# **************************************************************************** #
# EXECUTOR TARGET DESCRIPTION

EXECUTOR_NAME = executor
EXECUTOR_PATH = executor
EXECUTOR_FILE = build/libexecutor.a
EXECUTOR_SRCS = executor.c redirection.c forky_utils.c executor_utils.c forky_binary.c forky_builtin.c forky_builtin_rdr.c
EXECUTOR_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(EXECUTOR_SRCS))
EXECUTOR_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(EXECUTOR_SRCS))
EXECUTOR_LIBS = 
EXECUTOR_INCS = -I libft -I env_var -I builtins -I ft_printf -I .

# **************************************************************************** #
# TEST_EXEC_1.OUT TARGET DESCRIPTION

TEST_EXEC_1.OUT_NAME = test_exec_1.out
TEST_EXEC_1.OUT_PATH = tests
TEST_EXEC_1.OUT_FILE = tests/test_exec_1.out
TEST_EXEC_1.OUT_SRCS = executor_1.c
TEST_EXEC_1.OUT_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(TEST_EXEC_1.OUT_SRCS))
TEST_EXEC_1.OUT_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(TEST_EXEC_1.OUT_SRCS))
TEST_EXEC_1.OUT_LIBS = -l executor -L build -l readline -L build -l builtins -L build -l printf -L build -l tokenizer -L build -l env-var -L build -l ft -L build
TEST_EXEC_1.OUT_INCS = -I libft -I env_var -I builtins -I readline -I executor -I ft_printf -I .

# **************************************************************************** #
# ENV-VAR TARGET DESCRIPTION

ENV-VAR_NAME = env-var
ENV-VAR_PATH = env_var
ENV-VAR_FILE = build/libenv-var.a
ENV-VAR_SRCS = env_get_set.c env_import_export.c env_path.c env_rm.c
ENV-VAR_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(ENV-VAR_SRCS))
ENV-VAR_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(ENV-VAR_SRCS))
ENV-VAR_LIBS = 
ENV-VAR_INCS = -I env_var -I libft

# **************************************************************************** #
# PRINTF TARGET DESCRIPTION

PRINTF_NAME = printf
PRINTF_PATH = ft_printf
PRINTF_FILE = build/libprintf.a
PRINTF_SRCS = print_utils.c ft_printf.c parse.c print_values.c
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
MINISHELL_LIBS = -l executor -L build -l readline -L build -l builtins -L build -l printf -L build -l tokenizer -L build -l env-var -L build -l ft -L build
MINISHELL_INCS = -I tokenizer -I libft -I env_var -I builtins -I readline -I executor -I ft_printf -I .

# **************************************************************************** #
# FT TARGET DESCRIPTION

FT_NAME = ft
FT_PATH = libft
FT_FILE = build/libft.a
FT_SRCS = ft_strchr.c ft_split.c ft_strtrim.c ft_bzero.c ft_strnstr.c ft_strmapi.c dlst_del_elem.c ft_isprint.c ft_atoi.c dlst_pop_front.c dlst_insert.c ft_strdup.c dlst_del.c ft_tolower.c ft_strcmp.c ft_toupper.c ft_substr.c ft_memchr.c ft_putnbr_fd.c ft_strlcpy.c ft_itoa.c ft_memset.c ft_calloc.c dlst_push_front.c get_next_line.c dlst_size.c ft_strlen.c dlst_push_back.c ft_putchar_fd.c ft_isascii.c ft_memccpy.c ft_strlcat.c ft_putendl_fd.c ft_memcmp.c ft_isdigit.c ft_strrchr.c dlst_elem.c ft_putstr_fd.c ft_isalpha.c ft_strncmp.c ft_isalnum.c ft_memcpy.c ft_memmove.c dlst_pop_back.c ft_strjoin.c
FT_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(FT_SRCS))
FT_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(FT_SRCS))
FT_LIBS = 
FT_INCS = -I libft

# **************************************************************************** #
# READLINE TARGET DESCRIPTION

READLINE_NAME = readline
READLINE_PATH = readline
READLINE_FILE = build/libreadline.a
READLINE_SRCS = readline.c readline_utils.c
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
TEST_TOKEN_1.OUT_LIBS = -l executor -L build -l readline -L build -l builtins -L build -l printf -L build -l tokenizer -L build -l env-var -L build -l ft -L build
TEST_TOKEN_1.OUT_INCS = -I tokenizer -I libft -I env_var -I builtins -I readline -I executor -I ft_printf -I .

# **************************************************************************** #
# GENERIC RULES

.PHONY: all re clean fclean
.DEFAULT_GOAL = all

all: $(BUILTINS_FILE) $(TOKENIZER_FILE) $(EXECUTOR_FILE) $(ENV-VAR_FILE) $(PRINTF_FILE) $(FT_FILE) $(READLINE_FILE) $(TEST_EXEC_1.OUT_FILE) $(MINISHELL_FILE) $(TEST_TOKEN_1.OUT_FILE)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(BUILTINS_FILE) $(TOKENIZER_FILE) $(EXECUTOR_FILE) $(ENV-VAR_FILE) $(PRINTF_FILE) $(FT_FILE) $(READLINE_FILE) $(TEST_EXEC_1.OUT_FILE) $(MINISHELL_FILE) $(TEST_TOKEN_1.OUT_FILE)

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

$(TEST_EXEC_1.OUT_FILE): $(EXECUTOR_FILE) $(READLINE_FILE) $(BUILTINS_FILE) $(PRINTF_FILE) $(TOKENIZER_FILE) $(ENV-VAR_FILE) $(FT_FILE) $(TEST_EXEC_1.OUT_OBJS)
	@$(C_COMPILER) $(C_LFLAGS) $(C_STANDART) -o $(TEST_EXEC_1.OUT_FILE) $(TEST_EXEC_1.OUT_OBJS)  $(TEST_EXEC_1.OUT_LIBS)
	@printf 'Finished	\033[1;32m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(TEST_EXEC_1.OUT_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(TEST_EXEC_1.OUT_INCS) -o $@ -c $< -MMD

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

$(TEST_TOKEN_1.OUT_FILE): $(EXECUTOR_FILE) $(READLINE_FILE) $(BUILTINS_FILE) $(PRINTF_FILE) $(TOKENIZER_FILE) $(ENV-VAR_FILE) $(FT_FILE) $(TEST_TOKEN_1.OUT_OBJS)
	@$(C_COMPILER) $(C_LFLAGS) $(C_STANDART) -o $(TEST_TOKEN_1.OUT_FILE) $(TEST_TOKEN_1.OUT_OBJS)  $(TEST_TOKEN_1.OUT_LIBS)
	@printf 'Finished	\033[1;32m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(TEST_TOKEN_1.OUT_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(TEST_TOKEN_1.OUT_INCS) -o $@ -c $< -MMD

-include $(BUILTINS_DEPS) $(TOKENIZER_DEPS) $(EXECUTOR_DEPS) $(TEST_EXEC_1.OUT_DEPS) $(ENV-VAR_DEPS) $(PRINTF_DEPS) $(MINISHELL_DEPS) $(FT_DEPS) $(READLINE_DEPS) $(TEST_TOKEN_1.OUT_DEPS)
