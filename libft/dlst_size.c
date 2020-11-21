/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:15:22 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/18 23:38:02 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				dlst_size(t_node **root)
{
	size_t len;
	t_node *tmp;

	len = 0;
	tmp = *root;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
