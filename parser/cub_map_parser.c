/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:44:48 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 12:11:12 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_map_parser.h"

t_vec	get_map_size(t_line *start)
{
	t_vec size;

	size.x = 0;
	size.y = 0;
	while (start)
	{
		size.y++;
		size.x = fmax(size.x, start->size);
		start = start->next;
	}
	return (size);
}

int		set_map(t_vars *vars, char c, t_vec p)
{
	char val;

	if (c == '0')
		val = MAP_AIR;
	else if (c == '1')
		val = MAP_BLOCK;
	else if (set_sprite(vars, c, p))
		val = MAP_NOENTRY;
	else if (set_entity(vars, c, p) || set_player(vars, c, p))
		val = MAP_AIR;
	else if (set_player(vars, c, p) || set_pathfinder(vars, c, p))
		val = MAP_AIR;
	else if (c == ' ')
		val = MAP_EMPTY;
	else
		return (0);
	map_set(&vars->map, p.x, p.y, val);
	return (1);
}

void	handle_door_rotation(t_vars *vars)
{
	t_sprite	*curr;
	t_vec		pos;

	curr = vars->sprites;
	while (curr)
	{
		if (curr->kind == DOOR)
		{
			pos.x = (int)curr->pos.x;
			pos.y = (int)curr->pos.y;
			if (map_get(&(vars->map), pos.x - 1, pos.y)
			&& map_get(&(vars->map), pos.x + 1, pos.y))
				curr->dead = false;
			else if (map_get(&(vars->map), pos.x, pos.y - 1)
				&& map_get(&(vars->map), pos.x, pos.y + 1))
				curr->dead = true;
			else
				handle_error(vars, "Invalid door position.", NULL);
		}
		curr = curr->next;
	}
}

bool	is_map_valid(t_map *map)
{
	t_vec	p;
	int		val;

	p.x = 0;
	while (p.x < map->size.x)
	{
		p.y = 0;
		while (p.y < map->size.y)
		{
			val = map_get_val(map, p.x, p.y);
			if (val == MAP_AIR || val == MAP_NOENTRY)
			{
				if (map_get_val(map, p.x - 1, p.y) == MAP_EMPTY
					|| map_get_val(map, p.x + 1, p.y) == MAP_EMPTY
					|| map_get_val(map, p.x, p.y - 1) == MAP_EMPTY
					|| map_get_val(map, p.x, p.y + 1) == MAP_EMPTY)
					return (false);
			}
			p.y++;
		}
		p.x++;
	}
	return (true);
}
