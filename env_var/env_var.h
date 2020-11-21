/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:08:57 by handrow           #+#    #+#             */
/*   Updated: 2020/11/13 17:38:28 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_H
# define ENV_VAR_H

# include "dlst.h"

struct		s_env_var
{
	char	*key;
	char	*value;	
};

typedef t_node *t_env_containter;

/*
** Create env_containter from null-terminated string array
** Format of the string in the array:
** "KEY=VALUE" / "KEY="
**
** Return: NULL if allocation failes
*/
void		*env_import_from_arr(t_env_containter *env, const char **arr);

/*
** Create null-terminated string array from env_container
** Format of the string in the array:
** "KEY=VALUE" / "KEY="
**
** Return: NULL if allocation failes
*/
char		**env_export_to_arr(t_env_containter *env);

/*
** Return value of variable with such @key
** Returned string is constant!!!
**
** Return: NULL if no such variable at the container
*/
const char	*env_get(t_env_containter *env, const char *key);

/*
** Set varibale's value with such @key to @val
**
** Return: NULL if allocation failed
*/
void		*env_set(t_env_containter *env, const char *key, const char *val);

/*
** Remove variable with such @key from container
*/
void		env_rm(t_env_containter *env, const char *key);

/*
** Remove container and free all allocated memory
*/
void		env_rm_rf(t_env_containter *env);

/*
** Create and allocate variable from the string
** Format of the string in the array:
** "KEY=VALUE" / "KEY="
*/
struct s_env_var	*env_var_from_str(const char *str);

#endif
