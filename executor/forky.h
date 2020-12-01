/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forky.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 10:07:14 by handrow           #+#    #+#             */
/*   Updated: 2020/12/01 17:11:52 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORKY_H
# define FORKY_H

# include <sys/types.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "../instructions.h"
# include "env_var.h"

# define EXIT_STATUS_SIG_BASE 128
# define EXIT_STATUS_BAD_EXIT 128
# define EXIT_STATUS_UNKWN_CMD 127
# define EXIT_STATUS_BAD_EXEC 126
# define EXIT_STATUS_BLT_ERROR 2
# define EXIT_STATUS_ERROR 1

struct				s_forky_info
{
	char			**argv;
	t_pipe_ptr		in;
	t_pipe_ptr		ou;
	void			*forky_func;
	int				exit_code;
	bool			fork_flag;
	t_rdr_list		rdrs;
};

typedef pid_t		(*t_forky_func)(struct s_forky_info *, t_env_containter *);

pid_t				forky_binary(struct s_forky_info *info,
								t_env_containter *env);
pid_t				forky_builtin_rd(struct s_forky_info *info,
								t_env_containter *env);
pid_t				forky_builtin(struct s_forky_info *info,
								t_env_containter *env);
void				frk_close_pipe(t_pipe_ptr pip);
int					frk_connect_pipe(t_pipe_ptr pip, int std_fd);
int					frk_manage_fd(struct s_forky_info *info);
int					frk_do_rdr_list(t_rdr_list rdrs);

#endif
