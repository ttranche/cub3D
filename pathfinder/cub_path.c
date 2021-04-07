/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:32:23 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 11:00:36 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_path.h"

/*
** Allocates a table of t_vec based on the pathfinder result
*/

t_vec	*make_path(t_node *end)
{
	int		size;
	t_vec	*path;

	size = node_path_size(end);
	if (!end || size == 0)
		return (NULL);
	path = malloc(sizeof(t_vec) * (size + 1));
	if (!path)
		return (NULL);
	path[size].x = -999;
	path[size].y = -999;
	while (end)
	{
		path[--size] = end->pos;
		end = end->parent;
	}
	return (path);
}
