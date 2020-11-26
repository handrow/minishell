from package import generate_makefile

# LIBRARIES

LIBFT = {
	"name": "ft",
	"out": "libft",
	"type": "lib",
	"path": "libft",
	"sources": ["*.c"],
	"includes": ["libft"]
}

ENV_VAR = {
    "name": "env-var",
    "out": "env_var",
    "type": "lib",
    "path": "env_var",
    "sources": ["*.c"],
    "includes": ["env_var", "libft", "errors"]
}

BLT = {
    "name": "builtins",
    "out": "builtins",
    "type": "lib",
    "path": "builtins",
    "sources": ["*.c"],
    "includes": ["env_var", "libft"]
}

EXECR = {
    "name": "executor",
    "out": "executor",
    "type": "lib",
    "path": "executor",
    "sources": ["*.c"],
    "includes": ["libft", "env_var",  "builtins", "ft_printf", "errors", "signal", "."]
}

READLINE = {
    "name": "readline",
    "out": "readline",
    "type": "lib",
    "path": "readline",
    "sources": ["*.c"],
    "includes": ["readline", "libft"]
}

TOKENIZER = {
    "name": "tokenizer",
    "out": "tokenizer",
    "type": "lib",
    "path": "tokenizer",
    "sources": ["*.c"],
    "includes": ["tokenizer", "libft"]
}

PRINTF = {
    "name": "printf",
    "out": "ft_printf",
    "type": "lib",
    "path": "ft_printf",
    "sources": ["*.c"],
    "includes": ["libft", "ft_printf"]
}

ERR = {
	"name": "err-minishell",
	"out": "errors",
	"type": "lib",
	"path": "errors",
	"sources": ["*.c"],
	"includes": ["ft_printf"]
}

SIG = {
	"name": "signal",
	"out": "signal",
	"type": "lib",
	"path": "signal",
	"sources": ["*.c"],
	"includes": ["shell_signals"]
}

# EXECUTABLES

MIS = {
    "name": "minishell",
    "out": ".",
    "type": "prog",
    "sources": ["main.c"],
    "includes": ["tokenizer", "libft", "env_var", "builtins", "readline", "executor", "ft_printf", "shell_signals", "."],
    "peerdirs": [EXECR, READLINE, BLT, PRINTF, TOKENIZER, ENV_VAR, LIBFT, SIG],
}

TEST_EXECUTOR_1 = {
    "name": "test_exec_1.out",
    "out": "tests",
    "type": "prog",
    "path": "tests",
    "sources": ["executor_1.c"],
    "includes": ["errors", "libft", "env_var", "builtins", "readline", "executor", "ft_printf", "shell_signals"],
    "peerdirs": [EXECR, READLINE, BLT, ERR, PRINTF, TOKENIZER, ENV_VAR, LIBFT, SIG],
}

TEST_TOKENIZER = {
    "name": "test_token_1.out",
    "out": "tests",
    "type": "prog",
    "path": "tests",
    "sources": ["tokenizer_1.c"],
    "includes": ["errors", "tokenizer", "libft", "env_var", "builtins", "readline", "executor", "ft_printf", "."],
    "peerdirs": [EXECR, READLINE, BLT, ERR, PRINTF, TOKENIZER, ENV_VAR, LIBFT, SIG],
}

# BUNDLE MAIN

BUNDLE = {
    "type": "bundle",
    "name": "kastet66",
    "peerdirs": [MIS, TEST_EXECUTOR_1, TEST_TOKENIZER]
}

COMPILERS = {
    "c": {
        "flags": "-Wall -Wextra",
        "file_extension": "c",
        "std": "-std=c99",
        "binary": "clang",
    }
}

generate_makefile(BUNDLE, COMPILERS)