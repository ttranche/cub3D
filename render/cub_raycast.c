/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:12:03 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 11:50:30 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_raycast.h"

t_ray	get_init_ray(t_rot *rot, double x, double y)
{
	t_ray	ray;

	ray.st_cos.x = rot->cos > 0 ? floor(x + 1) - x : ceil(x - 1) - x;
	ray.st_cos.y = ray.st_cos.x * (rot->sin / rot->cos);
	ray.ln_cos = calc_sqrtlen(ray.st_cos);
	ray.st_sin.y = rot->sin > 0 ? floor(y + 1) - y : ceil(y - 1) - y;
	ray.st_sin.x = ray.st_sin.y * (rot->cos / rot->sin);
	ray.ln_sin = calc_sqrtlen(ray.st_sin);
	return (ray);
}

/*
** Calculates the texture offset for the main ray hit
*/

double	tex_offset(t_trace trace)
{
	double offset;

	if (trace.ray.ln_cos < trace.ray.ln_sin)
	{
		offset = trace.ref.x + trace.ref.y + trace.ray.st_cos.x
			+ trace.ray.st_cos.y;
		offset -= (int)offset;
		if (trace.rot.cos < 0)
			offset = 1 - offset;
	}
	else
	{
		offset = trace.ref.x + trace.ref.y + trace.ray.st_sin.x
			+ trace.ray.st_sin.y;
		offset -= (int)offset;
		if (trace.rot.sin > 0)
			offset = 1 - offset;
	}
	return (offset);
}

/*
** Setups the t_shape of the row (x) that'll be drawn to the main buffer,
** and some other stuff like the texture offset for it etc...
*/

void	setup_line(t_vars *vars, t_trace *tr)
{
	tr->card = get_cardinal(*tr);
	tr->len = fmin(tr->ray.ln_cos, tr->ray.ln_sin);
	vars->depth[tr->line.x] = fmin(tr->len, vars->depth[tr->line.x]);
	tr->line.height = vars->resy / (tr->len * cos(tr->newa));
	tr->line.y = (vars->resy - tr->line.height) / 2;
	tr->line.y += vars->player.pitch * 2;
	tr->line.y += tr->line.height * vars->player.render.z;
	tr->line.dim = 1 - fmin(1, (tr->len - 1) / 9);
	tr->line.img = get_texture(vars, tr->card);
	tr->offset = tex_offset(*tr);
	tr->pt = get_portal(vars, tr->pos.x, tr->pos.y, tr->card);
	if (!vars->should_dim)
		tr->line.dim = 1;
}

/*
** Handles the casting forward of the ray, and calls the draw functions if it
** does hit
*/

void	do_ray(t_vars *vars, t_trace *tr, t_img *img)
{
	tr->pos = get_collide_pos(*tr);
	if (check_colide(vars, tr->pos))
	{
		setup_line(vars, tr);
		if (tr->pt)
		{
			translate_portal(&(tr->ref), tr->card, tr->pt);
			portal_render_pf(&tr->portal, tr->line, tr->offset);
			cast_forward(&(tr->ray), tr->step);
			tr->i++;
			return ;
		}
		tr->pt = get_empty_portal(vars, tr->pos.x, tr->pos.y, tr->card);
		if (tr->pt)
			e_portal_strip(img, tr->line, &(vars->portal), tr->offset);
		else
			set_img_strip(img, tr->line, tr->offset);
		tr->i += 99;
		return ;
	}
	cast_forward(&(tr->ray), tr->step);
	tr->i++;
}

/*
** Starts all the ray casting for every row on the screen
*/

void	ray(t_vars *vars, t_img *img)
{
	t_trace	trace;
	int		max;

	trace.line.width = 1;
	trace.line.x = -1;
	max = (int)(vars->render_distance * 1.41) + 1;
	while (++trace.line.x < vars->resx)
	{
		vars->depth[trace.line.x] = 999;
		trace.newa = atan2((trace.line.x / (double)vars->resx) - .5, vars->fov);
		trace.rot = make_rot(vars->player.yaw + trace.newa);
		trace.ref.x = vars->player.render.x;
		trace.ref.y = vars->player.render.y;
		trace.ray = get_init_ray(&(trace.rot), trace.ref.x, trace.ref.y);
		trace.step = get_init_ray(&(trace.rot), 0, 0);
		trace.portal = NULL;
		trace.i = 0;
		while (trace.i < max)
			do_ray(vars, &trace, img);
		portal_foreach_free(trace.portal, &render_portal, vars);
	}
}
