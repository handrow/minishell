/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_opts.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:58:38 by handrow           #+#    #+#             */
/*   Updated: 2020/12/02 06:17:38 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_OPTS_H
# define CMD_OPTS_H

# include <stdbool.h>

# define CMD_OPTS_SIZE 2

# define CMD_OPTS_MINISHELL_MAJOR 1
# define CMD_OPTS_MINISHELL_MINOR 1
# define CMD_NOT_ELISTA_EDITION_FL "make_sence"
# define CMD_POSIX_FORMAT_FL "posix"

bool	*opts_opt(const char *opt_name);
void	opts_parse(char *av[]);
void	put_greetings(void);

#endif
