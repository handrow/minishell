/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:12:05 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/14 16:43:56 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				dlst_push_front(t_node **root, t_node *new_elem)
{
	if (!(*root))
		*root = new_elem;
	else
	{
		new_elem->next = *root;
		(*root)->prev = new_elem;
		*root = new_elem;
	}
}
