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
# MINISHELL TARGET DESCRIPTION

MINISHELL_NAME = minishell
MINISHELL_PATH = .
MINISHELL_FILE = ./minishell
MINISHELL_SRCS = main.c
MINISHELL_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(MINISHELL_SRCS))
MINISHELL_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(MINISHELL_SRCS))
MINISHELL_LIBS = -l builtins -L build -l ft -L build -l env-var -L build
MINISHELL_INCS = -I libft -I env_var -I builtins

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
# FT TARGET DESCRIPTION

FT_NAME = ft
FT_PATH = libft
FT_FILE = build/libft.a
FT_SRCS = dlst_del.c dlst_del_elem.c dlst_elem.c dlst_insert.c dlst_pop_back.c dlst_pop_front.c dlst_push_back.c dlst_push_front.c dlst_size.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_printf.c ft_printf_cs.c ft_printf_diux.c ft_printf_p.c ft_printf_pars.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_base_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c
FT_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(FT_SRCS))
FT_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(FT_SRCS))
FT_LIBS = 
FT_INCS = -I libft

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
# GENERIC RULES

.PHONY: all re clean fclean
.DEFAULT_GOAL = all

all: $(BUILTINS_FILE) $(FT_FILE) $(ENV-VAR_FILE) $(MINISHELL_FILE)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(BUILTINS_FILE) $(FT_FILE) $(ENV-VAR_FILE) $(MINISHELL_FILE)

re: fclean all

$(MINISHELL_FILE): $(BUILTINS_FILE) $(FT_FILE) $(ENV-VAR_FILE) $(MINISHELL_OBJS)
	@$(C_COMPILER) $(C_LFLAGS) $(C_STANDART) -o $(MINISHELL_FILE) $(MINISHELL_OBJS)  $(MINISHELL_LIBS)
	@printf 'Finished	\033[1;32m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(MINISHELL_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(MINISHELL_INCS) -o $@ -c $< -MMD

$(BUILTINS_FILE): $(BUILTINS_OBJS)
	@ar rc $(BUILTINS_FILE) $(BUILTINS_OBJS)
	@ranlib $(BUILTINS_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(BUILTINS_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(BUILTINS_INCS) -o $@ -c $< -MMD

$(FT_FILE): $(FT_OBJS)
	@ar rc $(FT_FILE) $(FT_OBJS)
	@ranlib $(FT_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(FT_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(FT_INCS) -o $@ -c $< -MMD

$(ENV-VAR_FILE): $(ENV-VAR_OBJS)
	@ar rc $(ENV-VAR_FILE) $(ENV-VAR_OBJS)
	@ranlib $(ENV-VAR_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(ENV-VAR_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(ENV-VAR_INCS) -o $@ -c $< -MMD

-include $(MINISHELL_DEPS) $(BUILTINS_DEPS) $(FT_DEPS) $(ENV-VAR_DEPS)
