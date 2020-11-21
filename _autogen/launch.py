from package import generate_makefile

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

READLINE = {
    "name": "readline",
    "out": "build",
    "type": "lib",
    "path": "readline",
    "sources": ["*.c"],
    "includes": ["readline", "libft"]
}

MIS = {
    "name": "minishell",
    "out": ".",
    "type": "prog",
    "sources": [
		"main.c",
	],
    "includes": ["libft", "env_var", "builtins", "readline"],
    "peerdirs": [LIBFT, ENV_VAR, BLT, READLINE],
}

COMPILERS = {
    "c": {
        "flags": "-Wall -Wextra",
        "file_extension": "c",
        "std": "-std=c99",
        "binary": "clang",
    }
}

generate_makefile(MIS, COMPILERS)