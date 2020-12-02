/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elista_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 05:24:02 by handrow           #+#    #+#             */
/*   Updated: 2020/12/02 06:22:09 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elista.h"
#include "cmd_opts.h"

static char		*elista_var_to_str(const struct s_env_var *var)
{
	const size_t	val_len = var->value ? ft_strlen(var->value) : 0;
	const size_t	len = ft_strlen(var->key) + val_len + 1;
	char *const		str = malloc(len + 3);

	if (!str)
		err_system_n_exit(1, NULL);
	ft_strlcpy(str, var->key, len + 3);
	if (var->value != NULL)
	{
		ft_strlcat(str, "=\"", len + 3);
		ft_strlcat(str, var->value, len + 3);
		ft_strlcat(str, "\"", len + 3);
	}
	return (str);
}

static char		**elista_export_to_arr(t_env_containter *env)
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
		if (!(var_str = elista_var_to_str(node->content)))
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

static int		elista_cmp(const char *s1, const char *s2)
{
	int	sym1;
	int	sym2;

	while ((*s1 != '=' || *s1 != '\0') && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	sym1 = *s1 == '=' ? 0 : (int)*s1;
	sym2 = *s2 == '=' ? 0 : (int)*s2;
	return (sym1 - sym2);
}

static void		elista_sort(char *arr[], int n)
{
	char		*tmp;
	int			i;
	int			j;

	j = 0;
	while (j < n - 1)
	{
		i = j + 1;
		while (i < n)
		{
			if (elista_cmp(arr[j], arr[i]) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
			++i;
		}
		++j;
	}
}

int				elista_output(t_env_containter *env)
{
	char		**elista_arr;
	const char	*elista_format;
	int			elista_size;
	int			i;

	elista_format = (*opts_opt(CMD_POSIX_FORMAT_FL) == true)
		? "export %s"
		: "declare -x %s";
	elista_arr = elista_export_to_arr(env);
	elista_size = 0;
	while (elista_arr[elista_size])
		++elista_size;
	elista_sort(elista_arr, elista_size);
	i = 0;
	while (i < elista_size)
	{
		ft_printf(STDOUT_FILENO, elista_format, elista_arr[i]);
		ft_printf(STDOUT_FILENO, "\n");
		++i;
	}
	str_arr_free(elista_arr);
	return (0);
}
