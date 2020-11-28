/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 07:54:34 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 08:45:43 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"
#include "err_msg.h"
#include "builtins.h"
#include <unistd.h>
#include <stdlib.h>

static const char	*get_cd_path(char **argv, t_env_containter *env)
{
	const char	*path;

	if (argv[1] == NULL)
	{
		if (!(path = env_get(env, "HOME")))
		{
			err_msg("cd", "HOME not set");
			return (NULL);
		}
	}
	else if (argv[2] == NULL)
	{
		path = argv[1];
	}
	else
	{
		err_msg("cd", "too many arguments");
		return (NULL);
	}
	return (path);
}

int					blt_cd(char **argv, t_env_containter *env)
{
	const char	*path;
	char		*old_pwd;
	char		*new_pwd;

	if (!(path = get_cd_path(argv, env)))
		return (1);
	if (!(old_pwd = get_pwd()))
	{
		err_system("cd");
		return (1);
	}
	if (chdir(path) < 0)
		err_system(path);
	if (!(new_pwd = get_pwd()))
	{
		free(old_pwd);
		err_system("cd");
		return (1);
	}
	env_set(env, "OLDPWD", old_pwd);
	env_set(env, "PWD", new_pwd);
	free(old_pwd);
	free(new_pwd);
	return (0);
}
