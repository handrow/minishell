/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:34:35 by handrow           #+#    #+#             */
/*   Updated: 2020/11/27 23:31:51 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"
#include <stdlib.h>
#include <stdbool.h>
#include "err_msg.h"
#include "libft.h"
#include "ft_printf.h"

static bool	parse_numeric(char *str, unsigned int *num)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '+' || str[i] == '-')
		++i;
	if (!ft_isdigit(str[i]))
		return (false);
	while (ft_isdigit(str[i]))
		++i;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] != '\0')
		return (false);
	*num = ft_atoi(str);
	return (true);
}

int			blt_exit(char **argv, t_env_containter *env)
{
	int	exit_status;

	(void)env;
	if (argv[1] && argv[2] == NULL)
	{
		if (parse_numeric(argv[1], (unsigned *)&exit_status) == true)
			exit(exit_status);
		else
			ft_printf(STDOUT_FILENO,
				"minishell: exit: %s: numeric argument required\n", argv[1]);
	}
	else if (argv[1] == NULL)
		exit(0);
	else
		err_msg("exit", "too many arguments");
	return (1);
}
