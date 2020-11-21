/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_pop_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:28:57 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/14 16:43:49 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*dlst_pop_front(t_node **root)
{
	t_node	*tmp;

	tmp = *root;
	*root = (*root)->next;
	if ((*root)->prev)
		(*root)->prev = NULL;
	return (tmp);
}
