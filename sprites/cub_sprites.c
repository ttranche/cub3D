/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:50:07 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:20:44 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_sprites.h"

/*
** Renders the actual sprite, which was setup in draw_sprite()
*/

void	draw_sprite_line(t_img *img, t_vars *vars, t_sprite s, t_sprite_r sp)
{
	while (++sp.v.x < sp.draw.width && sp.draw.x + sp.v.x < img->width)
	{
		if (sp.draw.x + sp.v.x < 0)
			sp.v.x = -sp.draw.x;
		sp.v.y = -1;
		sp.offset.x = fmin(sp.v.x / (double)sp.draw.width * s.texture->width,
			s.texture->width - 1);
		if (s.last_hurt % 15 > 7)
			sp.offset.x = fmax(0, s.texture->width - sp.offset.x - 1);
		while (++sp.v.y < sp.draw.height && sp.draw.y + sp.v.y < img->height)
		{
			if (sp.draw.y + sp.v.y < 0)
				sp.v.y = -sp.draw.y;
			if (sp.dist >= vars->depth[sp.draw.x + sp.v.x])
				continue;
			sp.offset.y = fmin(sp.v.y / (double)sp.draw.height
				* s.texture->height, s.texture->height - 1);
			sp.dim = !vars->should_dim ? 1 :
				fmax(0, fmin(1, 1 - fmin(1, (sp.dist - 1) / 9)));
			sp.color = get_pixel(s.texture, sp.offset.x, sp.offset.y);
			if (sp.color != 0)
				set_pixel(img, sp.draw.x + sp.v.x, sp.draw.y + sp.v.y,
					color_dim(sp.color, sp.dim));
		}
	}
}

/*
** Setups the sprite for render
*/

bool	draw_sprite(t_img *img, t_vars *vars, t_sprite s)
{
	t_sprite_r sp;

	if (s.kind == DOOR)
		return (false);
	sp.pos.x = s.pos.x - vars->player.render.x;
	sp.pos.y = s.pos.y - vars->player.render.y;
	sp.dist = distance(sp.pos);
	if (sp.dist > vars->render_distance)
		return (false);
	sp.sprite_angle = atan2(sp.pos.y, sp.pos.x) - vars->player.yaw;
	sp.view_dist = vars->resx * vars->fov;
	sp.draw.width = sp.view_dist / (cos(sp.sprite_angle) * sp.dist);
	sp.draw.x = vars->resx / 2 + (tan(sp.sprite_angle))
		* sp.view_dist - sp.draw.width / 2;
	sp.draw.height = sp.draw.width;
	sp.draw.y = (vars->resy - sp.draw.height + vars->player.pitch * 4) / 2
		+ sp.draw.height * vars->player.render.z;
	sp.v.x = -1;
	if (sp.draw.height > 0)
		draw_sprite_line(img, vars, s, sp);
	return (1);
}

/*
** Handles door opening and such
*/

void	handle_door(t_sprite *curr, t_vars *vars)
{
	t_sprite *cur;

	if (curr->last_hurt == 25)
	{
		cur = vars->sprites;
		while (cur)
		{
			if (!cur->dead && cur->kind == GOOMBA &&
				distancemid2(curr->pos, cur->pos) <= 0.9)
				return ;
			cur = cur->next;
		}
	}
	if (square_dist_mid(vars->player.pos, curr->pos) < 8)
	{
		if (curr->last_hurt == 0)
			play_sound(vars->sounds.door);
		curr->last_hurt = fmin(25, curr->last_hurt + 1);
	}
	else
		curr->last_hurt = fmax(0, curr->last_hurt - 1);
}

/*
** Calls all sprite drawing functions and handlers
*/

void	draw_sprites(t_vars *vars, bool skip)
{
	t_sprite	*curr;
	double		dist;

	sprite_sort(vars, &(vars->sprites));
	curr = vars->sprites;
	while (curr)
	{
		dist = square_dist(vars->player.pos, curr->pos);
		if (vars->bonus && curr->kind == DOOR
			&& (skip || draw_door(&(vars->img), vars, *curr)))
			handle_door(curr, vars);
		else if (!curr->dead && (skip || draw_sprite(&(vars->img), vars, *curr))
			&& curr->kind == GOOMBA && dist < 196)
			handle_goomba(curr, vars);
		curr = curr->next;
	}
}
