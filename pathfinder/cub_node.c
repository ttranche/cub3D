/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:15:33 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 12:04:25 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_node.h"

/*
**	Creates a node, nodes act as a chained list but also have a parent pointer,
**	which links to it's parent node (Which is kinda like a second list)
*/

t_node	*make_node(t_node *parent, t_vec end, t_vec pos)
{
	t_node *elem;

	if (!(elem = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	elem->pos = pos;
	elem->parent = parent;
	elem->next = NULL;
	elem->square_dist = square_dist2i(end, pos);
	return (elem);
}

/*
**	Returns the size of the node chained list size
*/

int		node_path_size(t_node *end)
{
	int i;

	i = 0;
	while (end)
	{
		++i;
		end = end->parent;
	}
	return (i);
}

/*
**	Removes a node from the list
*/

void	node_remove(t_node **begin_list, t_node *node)
{
	t_node *prev;
	t_node *aftr;

	prev = NULL;
	aftr = *begin_list;
	while (aftr)
	{
		if (aftr == node)
		{
			if (prev == NULL)
				*begin_list = aftr->next;
			else
				prev->next = aftr->next;
			break ;
		}
		prev = aftr;
		aftr = prev->next;
	}
}

/*
** Pushes a node to the begining of the list
*/

void	node_push(t_node **begin_list, t_node *node)
{
	node->next = *begin_list;
	*begin_list = node;
}

/*
** Inserts a node to the chained list in the right order
*/

void	node_insert(t_node **begin_list, t_node *node)
{
	t_node *last;
	t_node *prev;

	last = *begin_list;
	node->next = NULL;
	if (!last || (prev = NULL))
	{
		*begin_list = node;
		return ;
	}
	while (last)
	{
		if (last->square_dist > node->square_dist)
		{
			if (prev)
				prev->next = node;
			else
				*begin_list = node;
			node->next = last;
			return ;
		}
		prev = last;
		last = last->next;
	}
	prev->next = node;
}
