/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 05:22:43 by handrow           #+#    #+#             */
/*   Updated: 2020/11/23 20:52:03 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "dlst.h"

typedef int t_pipe[2];
typedef int *t_pipe_ptr;
typedef t_node *t_redirection_list;

// fix that perror isnt allowed only strerror

enum e_rdr
{
	RDR_IN, // <
	RDR_OUT, // >
	RDR_APPEND // >>
};

enum e_instruction
{
	IT_CMD,
	IT_PIPE
};

struct s_rdr
{
	enum e_rdr			type;
	char				*filename;	
};

struct s_instruction
{
	char				**argv;
	t_pipe				pipe;
	enum e_instruction	type;
	t_redirection_list	rdr_list;
};

#endif
