/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forky_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:20:38 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 07:38:23 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forky.h"

void	frk_close_pipe(t_pipe_ptr pip)
{
	close(pip[0]);
	close(pip[1]);
}

int		frk_connect_pipe(t_pipe_ptr pip, int std_fd)
{
	bool	is_error;

	is_error = dup2(pip[std_fd], std_fd) < 0;
	frk_close_pipe(pip);
	return (is_error ? -1 : 0);
}

int		frk_manage_fd(struct s_forky_info *info)
{
	bool			is_err;

	is_err = false;
	if (!is_err && info->in)
		is_err = (frk_connect_pipe(info->in, STDIN_FILENO) < 0);
	if (!is_err && info->ou)
		is_err = (frk_connect_pipe(info->ou, STDOUT_FILENO) < 0);
	if (!is_err && info->rdrs)
		is_err = frk_do_rdr_list(info->rdrs) < 0;
	return (is_err ? -1 : 0);
}
