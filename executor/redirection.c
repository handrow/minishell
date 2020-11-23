/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:45:49 by handrow           #+#    #+#             */
/*   Updated: 2020/11/23 21:27:23 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "forky.h"
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

static void		frk_do_rdr_item(struct s_rdr *rdr)
{
	const int	flags = get_flags(rdr->type);
	const int	mode = 0644;
	const int	fd = open(rdr->filename, flags, mode);
	
	if (fd >= 0)
	{
		dup2(fd, rdr->type == RDR_IN
					? STDIN_FILENO : STDOUT_FILENO);
		close(fd);
	}
	else
		perror(rdr->filename);
}

void			frk_do_rdr_list(t_rdr_list rdrs)
{
	while (rdrs)
	{
		frk_do_rdr_item(rdrs->content);
		rdrs = rdrs->next;
	}
}
