/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 22:45:16 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 11:11:37 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_floor.h"

/*
** Renders a single floor row, called by setup_floor() which setups the
** t_floor_render struct
*/

void	render_row_floor(t_vars *vars, t_floor_render *f)
{
	if (f->row_len < 0)
	{
		fill_img(vars->img, 0x0, vars->resy - f->s.y - 2, vars->resy - f->s.y);
		f->s.y += 2;
		return ;
	}
	f->s.x = 0;
	while (f->s.x < vars->resx)
	{
		f->tex.x = modabs(f->start_pos.x) * vars->floor.width;
		f->tex.y = modabs(f->start_pos.y) * vars->floor.height;
		f->color = get_pixel(&(vars->floor), (int)f->tex.x, (int)f->tex.y);
		f->dim = 1 - fmin(1, square_dist(vars->player.render, f->start_pos)
			/ 81);
		set_big_pixel(&(vars->img), f->s.x, vars->resy - f->s.y - 2,
			color_dim(f->color, f->dim));
		f->start_pos.x += f->step.x;
		f->start_pos.y += f->step.y;
		f->s.x += 2;
	}
	f->s.y += 2;
}

/*
** Sets up initial rotation angles and loops through the needed
** screen rows (y)
*/

void	setup_floor(t_vars *vars, t_floor_render *f)
{
	if (vars->resy < 8)
		return ;
	f->ang = atan2(0.5, vars->fov);
	f->start = make_rot(vars->player.yaw - f->ang);
	f->end = make_rot(vars->player.yaw + f->ang);
	f->mid = vars->resy / 2;
	f->midpi = fmin(vars->resy, f->mid - vars->player.pitch * 2);
	f->s.y = 0;
	while (f->s.y < f->midpi)
	{
		f->row_len = f->mid / (f->mid - f->s.y - vars->player.pitch * 2);
		f->row_len *= (vars->cam_width + (vars->player.render.z *
			vars->cam_width * 2));
		f->step.x = ((f->end.cos - f->start.cos) * f->row_len) / vars->resx * 2;
		f->step.y = ((f->end.sin - f->start.sin) * f->row_len) / vars->resx * 2;
		f->start_pos.x = vars->player.render.x + f->start.cos * f->row_len;
		f->start_pos.y = vars->player.render.y + f->start.sin * f->row_len;
		render_row_floor(vars, f);
	}
}

/*
** Draws the whole textured or untextured floor
*/

void	draw_floor(t_vars *vars)
{
	t_floor_render	floor;
	int				mid;

	if (!vars->floor.img)
	{
		mid = fmax(0, vars->img.height / 2 + vars->player.pitch * 2);
		fill_img(vars->img, vars->bottom_color, mid, vars->img.height);
		return ;
	}
	setup_floor(vars, &floor);
}
