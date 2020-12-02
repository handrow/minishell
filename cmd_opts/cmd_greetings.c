/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_greetings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 05:49:38 by handrow           #+#    #+#             */
/*   Updated: 2020/12/02 06:26:01 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_opts.h"
#include "ft_printf.h"
#include <unistd.h>

void	put_greetings(void)
{
	const bool is_elista = !*opts_opt(CMD_NOT_ELISTA_EDITION_FL);

	ft_printf(STDOUT_FILENO,
		"Welcome to our Minishell '%s' v.%d.%d\n"
		"Let the Greate Evaluation begins ( >.< )\n\n",
			is_elista ? "Elista Edition" : "Standart Edition",
			CMD_OPTS_MINISHELL_MAJOR, CMD_OPTS_MINISHELL_MINOR);
}
