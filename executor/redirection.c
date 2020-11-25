/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:45:49 by handrow           #+#    #+#             */
/*   Updated: 2020/11/25 16:46:03 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "forky.h"
#include "err_msg.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static int		get_flags(enum e_rdr type)
{
	if (type == RDR_OUT)
		return (O_CREAT | O_WRONLY | O_TRUNC);
	if (type == RDR_APPEND)
		return (O_CREAT | O_WRONLY | O_APPEND);
	if (type == RDR_IN)
		return (O_RDONLY);
	return (0);
}

static int		frk_do_rdr_item(struct s_rdr *rdr)
{
	const int	flags = get_flags(rdr->type);
	const int	mode = 0644;
	const int	fd = open(rdr->filename, flags, mode);
	
	if (fd >= 0)
	{
		if (dup2(fd, rdr->type == RDR_IN ? STDIN_FILENO : STDOUT_FILENO) < 0)
			return (-1);
		close(fd);
	}
	else
		return (-1);
	return (0);
}

int				frk_do_rdr_list(t_rdr_list rdrs)
{
	while (rdrs)
	{
		if (frk_do_rdr_item(rdrs->content) < 0)
		{
			err_system_n_exit(EXIT_STATUS_ERROR,
				((struct s_rdr *)rdrs->content)->filename);
		}
		rdrs = rdrs->next;
	}
	return (0);
}
