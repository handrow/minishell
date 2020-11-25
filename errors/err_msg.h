/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:20:47 by handrow           #+#    #+#             */
/*   Updated: 2020/11/25 15:56:19 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_H
# define ERR_MSG_H

void	err_msg(const char *msg, const char *ap);
void	err_system(const char *ap);
void	err_msg_n_exit(int exit_code, const char *msg, const char *ap);
void	err_system_n_exit(int exit_code, const char *ap);

#endif
