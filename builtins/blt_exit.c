/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:34:35 by handrow           #+#    #+#             */
/*   Updated: 2020/11/27 21:36:38 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"
#include <stdlib.h>

int		blt_exit(char **argv, t_env_containter *env)
{
	(void)argv;
	(void)env;
	exit(0);
	return (0);
}
