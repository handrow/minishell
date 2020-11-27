/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 03:52:30 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/27 22:33:55 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include <string.h>

# ifndef RDL_BUFFER_SIZE
#  define RDL_BUFFER_SIZE 64
# endif

typedef struct	s_string
{
	char		*str;
	size_t		len;
}				t_string;

int				readline(char **line);
void			put_prompt(void);
char			*find_first_sym(char *s, char *symbs);

#endif
