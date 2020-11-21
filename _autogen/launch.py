from package import generate_makefile

LIBFT = {
	"name": "ft",
	"out": "build",
	"type": "lib",
	"path": "libft",
	"sources": ["*.c"],
	"includes": ["libft"]
}
MIS = {
    "name": "minishell",
    "out": ".",
    "type": "prog",
    "sources": [
		"main.c",
	],
    "includes": ["libft"],
    "peerdirs": [LIBFT],
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