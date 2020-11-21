/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:11:57 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/16 16:31:45 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				dlst_del(t_node **root, t_del_func deletor)
{
	while ((*root)->next)
	{
		dlst_del_elem(root, *root, deletor);
	}
	dlst_del_elem(root, *root, deletor);
	*root = NULL;
}
