/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_star_cardinal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:15:10 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 11:02:38 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_star_cardinal.h"

/*
** Gets the neighbors of the current t_vec
*/

t_vec	get_neighbor(int rot, t_vec origin)
{
	if (rot == 0)
		origin.x++;
	else if (rot == 1)
		origin.x--;
	else if (rot == 2)
		origin.y++;
	else if (rot == 3)
		origin.y--;
	return (origin);
}

bool	is_in_map(t_map *map, t_vec pos)
{
	if (pos.x < 0 || pos.y < 0)
		return (false);
	if (pos.x >= map->size.x || pos.y >= map->size.y)
		return (false);
	return (true);
}
