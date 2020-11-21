from package import generate_makefile

# LIBRARIES

LIBFT = {
	"name": "ft",
	"out": "build",
	"type": "lib",
	"path": "libft",
	"sources": ["*.c"],
	"includes": ["libft"]
}

ENV_VAR = {
    "name": "env-var",
    "out": "build",
    "type": "lib",
    "path": "env_var",
    "sources": ["*.c"],
    "includes": ["env_var", "libft"]
}

BLT = {
    "name": "builtins",
    "out": "build",
    "type": "lib",
    "path": "builtins",
    "sources": ["*.c"],
    "includes": ["env_var", "libft"]
}

EXECR = {
    "name": "executor",
    "out": "build",
    "type": "lib",
    "path": "executor",
    "sources": ["*.c"],
    "includes": ["env_var", "libft", "builtins", "ft_printf", "."]
}

READLINE = {
    "name": "readline",
    "out": "build",
    "type": "lib",
    "path": "readline",
    "sources": ["*.c"],
    "includes": ["readline", "libft"]
}

PRINTF = {
    "name": "printf",
    "out": "build",
    "type": "lib",
    "path": "ft_printf",
    "sources": ["*.c"],
    "includes": ["libft", "ft_printf"]
}

# EXECUTABLES

MIS = {
    "name": "minishell",
    "out": ".",
    "type": "prog",
    "sources": ["main.c"],
    "includes": ["libft", "env_var", "builtins", "readline", "executor", "ft_printf", "."],
    "peerdirs": [LIBFT, ENV_VAR, BLT, READLINE, EXECR, PRINTF],
}

TEST_EXECUTOR_1 = {
    "name": "test_exec_1.out",
    "out": "tests",
    "type": "prog",
    "path": "tests",
    "sources": ["main_executor_1.c"],
    "includes": ["libft", "env_var", "builtins", "readline", "executor", "ft_printf", "."],
    "peerdirs": [LIBFT, ENV_VAR, BLT, READLINE, EXECR, PRINTF],
}

# BUNDLE MAIN

BUNDLE = {
    "type": "bundle",
    "name": "kastet66",
    "peerdirs": [MIS, TEST_EXECUTOR_1]
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