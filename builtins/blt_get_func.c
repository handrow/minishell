/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_get_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 04:04:37 by handrow           #+#    #+#             */
/*   Updated: 2020/11/28 00:23:50 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"

t_builtin_func	blt_get_func(const char *name)
{
	if (name == NULL)
		return (blt_dummy);
	else if (ft_strcmp("exit", name) == 0)
		return (blt_exit);
	else if (ft_strcmp("env", name) == 0)
		return (blt_env);
	else if (ft_strcmp("export", name) == 0)
		return (blt_export);
	return (NULL);
}
