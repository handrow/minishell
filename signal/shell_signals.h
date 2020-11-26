/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:17:03 by handrow           #+#    #+#             */
/*   Updated: 2020/11/26 18:40:09 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_SIGNALS_H
# define SHELL_SIGNALS_H

# include <stdbool.h>

extern bool	g_sigint;
extern bool	g_sigquit;

void		sig_set(void);
void		sig_reset(void);

#endif
