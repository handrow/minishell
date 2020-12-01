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
    "includes": ["env_var", "libft", "errors", "ft_printf"]
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
    "includes": ["readline", "libft", "signal", "ft_printf"]
}

TOKENIZER = {
    "name": "tokenizer",
    "out": "tokenizer",
    "type": "lib",
    "path": "tokenizer",
    "sources": ["*.c"],
    "includes": ["tokenizer", "ft_printf", "libft", "errors"]
}

PARSER = {
    "name": "parser",
    "out": "parser",
    "type": "lib",
    "path": "parser",
    "sources": ["*.c"],
    "includes": ["tokenizer", "ft_printf", "errors", "env_var", "parser", "libft", "."]
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
	"includes": ["shell_signals", "readline", "ft_printf"]
}

# EXECUTABLES

MIS = {
    "name": "minishell",
    "out": ".",
    "type": "prog",
    "sources": ["main.c"],
    "includes": ["tokenizer", "parser", "errors", "libft", "env_var", "builtins", "readline", "executor", "ft_printf", "signal", "."],
    "peerdirs": [EXECR, PARSER, READLINE, BLT, PRINTF, TOKENIZER, ENV_VAR, LIBFT, ERR, SIG],
}

COMPILERS = {
    "c": {
        "flags": "-Wall -Wextra -Werror",
        "file_extension": "c",
        "std": "-std=c99",
        "binary": "clang",
    }
}

generate_makefile(MIS, COMPILERS)