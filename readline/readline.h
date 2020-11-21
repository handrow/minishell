/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 03:52:30 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/21 05:45:52 by jiandre          ###   ########.fr       */
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
char			*find_first_sym(char *s, char *symbs);

#endif
