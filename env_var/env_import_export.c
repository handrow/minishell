/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_import_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:35:49 by handrow           #+#    #+#             */
/*   Updated: 2020/12/01 19:09:12 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"
#include "libft.h"
#include "err_msg.h"

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
		err_system_n_exit(1, NULL);
	if (!(var->key = ft_substr(str, 0, key_len)))
		err_system_n_exit(1, NULL);
	if (!(var->value = ft_strdup(val_start)))
		err_system_n_exit(1, NULL);
	return (var);
}

char				*env_var_to_str(const struct s_env_var *var)
{
	const size_t	len = ft_strlen(var->key) + ft_strlen(var->value) + 1;
	char *const		str = malloc(len + 1);

	if (!str)
		err_system_n_exit(1, NULL);
	ft_strlcpy(str, var->key, len + 1);
	ft_strlcat(str, "=", len + 1);
	ft_strlcat(str, var->value, len + 1);
	return (str);
}

void				*env_import_from_arr(t_env_containter *env,
										const char **arr)
{
	struct s_env_var	*var;
	t_node				*node;
	int					i;

	i = 0;
	while (arr[i])
	{
		if (!(var = env_var_from_str(arr[i])))
			err_system_n_exit(1, NULL);
		if (!(node = dlst_elem(var)))
			err_system_n_exit(1, NULL);
		dlst_push_front(env, node);
		++i;
	}
	return (*env);
}

char				**env_export_to_arr(t_env_containter *env)
{
	const size_t	len = dlst_size(env);
	char **const	arr = malloc((len + 1) * sizeof(char *));
	const t_node	*node = *env;
	char			*var_str;
	int				i;

	i = 0;
	if (!arr)
		err_system_n_exit(1, NULL);
	while (node)
	{
		if (!(var_str = env_var_to_str(node->content)))
			err_system_n_exit(1, NULL);
		if (var_str[0] == '?' && var_str[1] == '=')
			free(var_str);
		else
			arr[i++] = var_str;
		node = node->next;
	}
	arr[i] = NULL;
	return (arr);
}
