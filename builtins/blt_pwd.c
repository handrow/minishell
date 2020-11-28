/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 08:13:24 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 08:45:03 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"
#include "err_msg.h"
#include "ft_printf.h"
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#define PWD_BUFF_BLK_SZ 2048

char	*get_pwd(void)
{
	char	*pwd_buff;
	size_t	pwd_buff_size;

	pwd_buff_size = PWD_BUFF_BLK_SZ;
	while (true)
	{
		pwd_buff = malloc(pwd_buff_size);
		if (!pwd_buff)
			err_system_n_exit(2, NULL);
		if (getcwd(pwd_buff, pwd_buff_size) == NULL)
		{
			free(pwd_buff);
			if (errno != ERANGE)
				return (NULL);
			pwd_buff_size += PWD_BUFF_BLK_SZ;
		}
		else
			return (pwd_buff);
	}
}

int		blt_pwd(char **argv, t_env_containter *env)
{
	char	*pwd;

	(void)env;
	if (argv[1] != NULL)
	{
		err_msg("pwd", "too many arguments");
		return (1);
	}
	pwd = get_pwd();
	if (!pwd)
	{
		err_system("pwd");
		return (1);
	}
	ft_printf(STDOUT_FILENO, "%s\n", pwd);
	free(pwd);
	return (0);
}
