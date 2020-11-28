/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_del_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:07:00 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/28 07:45:09 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dlst_del_elem(t_node **root, t_node *node, t_del_func deletor)
{
	t_node *tmp;

	if (node == *root)
	{
		tmp = (*root)->next;
		if (node->next)
			node->next->prev = NULL;
		deletor(node->content);
		node->next = NULL;
		free(node);
		*root = tmp;
	}
	else
	{
		if (node->prev)
			node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		deletor(node->content);
		node->prev = NULL;
		node->next = NULL;
		free(node);
	}
}
