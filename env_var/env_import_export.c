/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_import_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:35:49 by handrow           #+#    #+#             */
/*   Updated: 2020/11/14 23:57:42 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"
#include "libft.h"

struct s_env_var	*env_var_from_str(const char *str)
{
	struct s_env_var	*var;
	size_t				key_len;
	char				*key_end;
	char				*val_start;
	
	key_end = ft_strchr(str, '=');
	key_len = (key_end == NULL)
		? ft_strlen(str)
		: key_end - str;
	val_start = (key_end == NULL) 
		? ""
		: key_end + 1;
	if (!(var = malloc(sizeof(struct s_env_var))))
		return (NULL);
	var->key = ft_substr(str, 0, key_len); // manage error
	var->value = ft_strdup(val_start); // manage error
	return (var);
}

char				*env_var_to_str(const struct s_env_var *var)
{
	const size_t	len = ft_strlen(var->key) + ft_strlen(var->value) + 1;
	char *const		str = malloc(len + 1); // manage error
	
	ft_strlcpy(str, var->key, len + 1);
	ft_strlcat(str, "=", len + 1);
	ft_strlcat(str, var->value, len + 1);
	return (str);
}

void		*env_import_from_arr(t_env_containter *env, const char **arr)
{
	struct s_env_var	*var;
	t_node 				*node;
	int					i;

	i = 0;
	while (arr[i])
	{
		var = env_var_from_str(arr[i]); // manage error
		node = dlst_elem(var); // manage error
		dlst_push_front(env, node);
		++i;
	}
	return (*env);
}

// env -> node_ptr -> (t_node)[ ... ]
// t_node.content -> (struct env_var)[ ... ]

char		**env_export_to_arr(t_env_containter *env)
{
	const size_t	len = dlst_size(env);
	char **const	arr = malloc((len + 1) * sizeof(char *)); // manage error
	const t_node	*node = *env;
	int				i;

	i = 0;
	while (node)
	{
		arr[i] = env_var_to_str(node->content); // manage error
		node = node->next;
		++i;
	}
	arr[i] = NULL;
	return (arr);
}