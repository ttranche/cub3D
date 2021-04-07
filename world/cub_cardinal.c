/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cardinal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 21:27:38 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 12:29:31 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_cardinal.h"

/*
** Gets a cardinal direction based on a raycast hit
*/

t_cardinal	get_cardinal(t_trace trace)
{
	if (trace.ray.ln_cos > trace.ray.ln_sin)
	{
		if (trace.rot.sin > 0)
			return (EAST);
		else
			return (WEST);
	}
	if (trace.rot.cos > 0)
		return (NORTH);
	else
		return (SOUTH);
}

/*
** Gets the opposite cardinal direction, used for portals
*/

t_cardinal	get_opposite(t_cardinal card)
{
	if (card == NORTH)
		return (SOUTH);
	if (card == SOUTH)
		return (NORTH);
	if (card == (EAST))
		return (WEST);
	return (EAST);
}

/*
** Gets a direction vector based on the cardinal direction
*/

t_vec		get_direction(t_cardinal card)
{
	t_vec vec;

	vec.x = 0;
	vec.y = 0;
	if (card == NORTH)
		vec.x = 1;
	else if (card == SOUTH)
		vec.x = -1;
	else if (card == EAST)
		vec.y = 1;
	else
		vec.y = -1;
	return (vec);
}
