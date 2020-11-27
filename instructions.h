/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 05:22:43 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 00:58:47 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "dlst.h"

typedef int t_pipe[2];
typedef int *t_pipe_ptr;
typedef t_node *t_rdr_list;

// fix that perror isnt allowed only strerror
typedef t_node		*t_instruction_list;

enum e_rdr
{
	RDR_IN = 0b1, // <
	RDR_OUT = 0b10, // >
	RDR_APPEND = 0b100 // >>
};

enum e_instruction
{
	IT_CMD,
	IT_PIPE
};

struct					s_rdr
{
	enum e_rdr			type;
	char				*filename;	
};

struct 					s_instruction
{
	char				**argv;
	t_pipe				pipe;
	enum e_instruction	type;
	t_rdr_list			rdr_list;
};

#endif
