/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_dummy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 04:00:04 by handrow           #+#    #+#             */
/*   Updated: 2020/11/21 04:14:43 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <unistd.h>

int	blt_dummy(char **argv, t_env_containter *env)
{
	(void)argv;
	(void)env;
	write(1, "hello\n", 6);
	return (4);
}
