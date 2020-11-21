/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:19:11 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/16 16:26:31 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLST_H
# define DLST_H

# include <stddef.h>

typedef struct		s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef void		(*t_del_func)(void *);

void				dlst_insert(t_node **node, t_node *new_elem);
void				dlst_push_back(t_node **root, t_node *new_elem);
void				dlst_push_front(t_node **root, t_node *new_elem);
t_node				*dlst_pop_back(t_node **root);
t_node				*dlst_pop_front(t_node **root);
t_node				*dlst_elem(void *content);
void				dlst_del_elem(t_node **root, t_node *node, t_del_func deletor);
void				dlst_del(t_node **root, t_del_func deletor);
size_t				dlst_size(t_node **root);

#endif
