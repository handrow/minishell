/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:44:27 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/25 22:02:23 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		dlst_insert(t_node **root, t_node *after, t_node *new_list)
{
	t_node	*last;

	if (!(*root) && (new_list))
		*root = new_list;
	else if (!new_list)
		return ;
	else if (!after || !after)
	{
		while (new_list->next)
			new_list = new_list->next;
		dlst_push_front(root, new_list);
	}
	else
	{
		new_list->prev = after;
		last = new_list;
		while (last->next)
			last = last->next;
		last->next = after->next;
		if (after->next)
			after->next->prev = last;
		after->next = new_list;
	}
}
