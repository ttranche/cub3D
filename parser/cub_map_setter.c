/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:46:18 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 12:11:57 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_map_setter.h"

int		set_player(t_vars *vars, char c, t_vec p)
{
	int val;

	if (c == 'E')
		val = 0;
	else if (c == 'S')
		val = 1;
	else if (c == 'W')
		val = 2;
	else if (c == 'N')
		val = 3;
	else
		return (0);
	if (vars->player.health != 0)
		handle_error(vars, "Duplicate player in map.", NULL);
	vars->player = make_player();
	vars->player.pos.x = p.x + 0.50001;
	vars->player.pos.y = p.y + 0.50001;
	vars->player.s_pos.x = vars->player.pos.x;
	vars->player.s_pos.y = vars->player.pos.y;
	vars->player.yaw = M_PI / 2.0 * val;
	return (1);
}

int		set_sprite(t_vars *vars, char c, t_vec p)
{
	t_vecd		pos;

	pos.x = p.x + 0.5;
	pos.y = p.y + 0.5;
	if (c == '2')
		sprite_pf(&(vars->sprites), pos, OBJ, &(vars->sprite_img));
	else if (vars->bonus && c == 'D')
	{
		pos.x = p.x;
		pos.y = p.y;
		sprite_pf(&(vars->sprites), pos, DOOR, &(vars->door_img));
	}
	else
		return (0);
	return (1);
}

int		set_entity(t_vars *vars, char c, t_vec p)
{
	t_vecd		pos;

	pos.x = p.x + 0.5;
	pos.y = p.y + 0.5;
	if (vars->bonus && c == 'G')
		sprite_pf(&(vars->sprites), pos, GOOMBA, &(vars->goomba_img));
	else if (vars->bonus && c == 'H')
		sprite_pf(&(vars->sprites), pos, HEALTH, &(vars->health_img));
	else
		return (0);
	return (1);
}

int		set_pathfinder(t_vars *vars, char c, t_vec p)
{
	if (vars->bonus && c == 'P')
	{
		if (vars->pathfinder.x != -1)
			handle_error(vars, "Duplicate pathfinder in map.", NULL);
		vars->pathfinder = p;
		return (1);
	}
	return (0);
}
