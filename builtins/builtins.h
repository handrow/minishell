/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 03:52:16 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 08:30:25 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <sys/types.h>
# include "env_var.h"

typedef int		(*t_builtin_func)(char **, t_env_containter *);

t_builtin_func	blt_get_func(const char *name);

char			*get_pwd(void);

int				blt_dummy(char **argv, t_env_containter *env);
int				blt_exit(char **argv, t_env_containter *env);
int				blt_env(char **argv, t_env_containter *env);
int				blt_export(char **argv, t_env_containter *env);
int				blt_unset(char **argv, t_env_containter *env);
int				blt_echo(char **argv, t_env_containter *env);
int				blt_pwd(char **argv, t_env_containter *env);
int				blt_cd(char **argv, t_env_containter *env);

#endif
