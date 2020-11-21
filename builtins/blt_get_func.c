/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_get_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 04:04:37 by handrow           #+#    #+#             */
/*   Updated: 2020/11/21 04:07:07 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"

t_builtin_func	blt_get_func(const char *name)
{
	if (ft_strcmp(name, "dummy") == 0)
		return (blt_dummy);
	return (NULL);
}
