/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elista_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:22:45 by handrow           #+#    #+#             */
/*   Updated: 2020/12/02 05:25:02 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elista.h"

static bool	is_var(char *str)
{
	while (*str != '\0' && *str != '=')
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (false);
		++str;
	}
	return (true);
}

static bool	add_var(char *str, t_env_containter *env)
{
	struct s_env_var	*var;

	if (!is_var(str))
	{
		ft_printf(STDOUT_FILENO, "minishell:"
		" export: `%s`: not a valid identifier\n", str);
		return (false);
	}
	var = env_var_from_str(str);
	if (!var)
		err_system_n_exit(1, "export");
	env_set(env, var->key, var->value);
	free(var->key);
	free(var->value);
	free(var);
	return (true);
}

int			blt_elista_export(char **argv, t_env_containter *env)
{
	int					i;
	int					is_err;

	i = 1;
	is_err = 0;
	if (argv[1] == NULL)
		return (elista_output(env));
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
