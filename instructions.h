/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 05:22:43 by handrow           #+#    #+#             */
/*   Updated: 2020/11/21 05:25:26 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

typedef int t_pipe[2];

enum e_instruction
{
	IT_CMD,
	IT_PIPE
};

struct s_instruction
{
	char				**argv;
	t_pipe				pipe;
	enum e_instruction	type;
	// TODO: add redir_list
};

#endif
