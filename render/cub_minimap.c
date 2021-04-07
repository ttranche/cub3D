/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:42:29 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 11:05:06 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_minimap.h"

/*
** Draws a cube, used by the minimap drawer: draw_minimap()
*/

void	draw_rects(t_vec v, t_shape rec, t_vars *vars)
{
	int i;

	if (map_get(&vars->map, v.x + (int)(vars->player.s_pos.x), v.y
		+ (int)(vars->player.s_pos.y)))
		rect(&(vars->blur.dest), rec, 0xA07BADCD);
	i = 0;
	while (vars->last_path && vars->last_path[i].x != -999)
	{
		if ((v.x + (int)(vars->player.s_pos.x)) == vars->last_path[i].x &&
			(v.y + (int)(vars->player.s_pos.y)) == vars->last_path[i].y)
		{
			rect(&(vars->blur.dest), rec, 0xC0D34141);
		}
		i++;
	}
}

/*
** Draws the actual minimap overlay to the blur buffer
*/

void	draw_minimap(t_vars *vars)
{
	t_vec	v;
	t_shape	rec;

	vars->player.s_pos.x -= (vars->player.s_pos.x - vars->player.pos.x) * 0.17;
	vars->player.s_pos.y -= (vars->player.s_pos.y - vars->player.pos.y) * 0.17;
	rec.width = 12;
	rec.height = 12;
	rec.x = -fabs(fmod(vars->player.s_pos.x, 1)) * rec.width;
	v.x = -9;
	while (++v.x <= 8)
	{
		v.y = -6;
		rec.y = -fabs(fmod(vars->player.s_pos.y, 1)) * rec.height;
		while (v.y <= 7)
		{
			draw_rects(v, rec, vars);
			rec.y += rec.height + 1;
			v.y++;
		}
		rec.x += rec.width + 1;
	}
	draw_minidot(vars);
}

/*
** Draws the player at the center of the map
*/

void	draw_minidot(t_vars *vars)
{
	t_shape	rec;
	float	f;

	f = 0;
	rec.height = 2;
	rec.width = 2;
	while (f < 1)
	{
		f += 0.1f;
		rec.x = 105 + (cos(vars->player.yaw) * f) * 10;
		rec.y = 77 + (sin(vars->player.yaw) * f) * 10;
		rect(&(vars->blur.dest), rec, 0xD7FFFFFF);
	}
	rec.x = 104;
	rec.y = 77;
	rect(&(vars->blur.dest), rec, 0x00000000);
}
