/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:22:45 by handrow           #+#    #+#             */
/*   Updated: 2020/12/01 17:04:56 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"
#include "builtins.h"
#include "libft.h"
#include "ft_printf.h"
#include "err_msg.h"
#include <stdbool.h>

static bool	is_var(char *str, char **end)
{
	while (*str != '\0' && *str != '=')
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (false);
		++str;
	}
	*end = str;
	return (*str == '=');
}

static bool	add_var(char *str, t_env_containter *env)
{
	char				*val_str;
	char				*key_str;

	if (!is_var(str, &val_str))
	{
		ft_printf(STDOUT_FILENO, "minishell:"
		" export: `%s`: not a valid identifier\n", str);
		return (false);
	}
	if (!(key_str = ft_substr(str, 0, val_str - str)))
		err_system_n_exit(1, "export");
	env_set(env, key_str, val_str + 1);
	free(key_str);
	return (true);
}

int			blt_export(char **argv, t_env_containter *env)
{
	int					i;
	int					is_err;

	i = 1;
	is_err = 0;
	if (argv[1] == NULL)
		return (blt_env(argv, env));
	else
	{
		while (argv[i])
		{
			is_err = !add_var(argv[i], env) || is_err;
			++i;
		}
	}
	return (is_err);
}
