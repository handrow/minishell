/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 10:45:54 by jiandre           #+#    #+#             */
/*   Updated: 2020/05/24 00:41:17 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*it;
	t_list	*tmp;

	if (!lst)
		return ;
	it = *lst;
	while (it)
	{
		tmp = it;
		it = it->next;
		ft_lstdelone(tmp, del);
	}
	*lst = 0;
}
