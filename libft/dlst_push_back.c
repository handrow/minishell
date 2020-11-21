/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:05:06 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/14 16:43:02 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				dlst_push_back(t_node **root, t_node *new_elem)
{
	t_node *tmp;

	if (!(*root))
		*root = new_elem;
	else
	{
		tmp = *root;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem;
		new_elem->prev = tmp;
	}
}
