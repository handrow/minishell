/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:39:23 by handrow           #+#    #+#             */
/*   Updated: 2020/11/19 00:16:13 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"
#include "libft.h"

const char	*env_get(t_env_containter *env, const char *key)
{
	const t_node			*node = *env;
	const struct s_env_var	*var;

	while (node)
	{
		var = node->content;
		if (ft_strcmp(var->key, key) == 0)
			return (var->value);
		node = node->next;
	}
	return (NULL);
}

void		*env_set(t_env_containter *env, const char *key, const char *val)
{
	t_node				*node;
	struct s_env_var	*var;
	
	node = *env;
	while (node)
	{
		var = node->content;
		if (ft_strcmp(var->key, key) == 0)
		{
			free(var->value);
			var->value = ft_strdup(val);
			return (var->value);
		}
		node = node->next;
	}
	var = malloc(sizeof(struct s_env_var)); // manage error
	var->key = ft_strdup(key); // manage error
	var->value = ft_strdup(val); // manage error
	node = dlst_elem(var); // manage error
	dlst_push_front(env, node);
	return (node);
}