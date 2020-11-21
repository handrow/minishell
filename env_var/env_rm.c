/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_rm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:59:09 by handrow           #+#    #+#             */
/*   Updated: 2020/11/18 21:04:36 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"
#include "dlst.h"
#include "libft.h"

void	env_var_del(void *env_var_ptr)
{
	struct s_env_var	*var;

	var = env_var_ptr;
	free(var->key);
	free(var->value);
	free(var);
}

void	env_rm(t_env_containter *env, const char *key)
{
	t_node				*node;
	struct s_env_var	*var;

	node = *env;
	while (node)
	{
		var = node->content;
		if (ft_strcmp(var->key, key) == 0)
		{
			dlst_del_elem(env, node, env_var_del);
			return ;
		}
		node = node->next;
	}
}

void	env_rm_rf(t_env_containter *env)
{
	dlst_del(env, env_var_del);
}
