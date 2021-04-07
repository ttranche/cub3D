/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_collide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:41:01 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 13:18:59 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_collide.h"

void	init_obj(t_vec3d *vec, double x, double y)
{
	vec->x = x;
	vec->y = y;
	vec->z = 0;
}

bool	collide_object(t_vars *vars, double x, double y, t_sprite *goomba)
{
	t_vec3d		vec;
	t_sprite	*curr;

	init_obj(&vec, x, y);
	curr = vars->sprites;
	while (curr)
	{
		if (goomba && curr != goomba && curr->kind == GOOMBA && !curr->dead &&
			square_dist(vec, curr->pos) < 0.45)
			return (true);
		else if (!goomba && curr->kind == HEALTH && !curr->dead
			&& square_dist(vec, curr->pos) < .14 && vars->player.health < 1)
		{
			curr->dead = true;
			vars->player.health = fmin(1, vars->player.health + 0.35);
			play_sound(vars->sounds.heal);
		}
		else if (curr->kind == OBJ && square_dist(vec, curr->pos) < 0.26)
			return (vars->bonus);
		else if (curr->kind == DOOR && curr->last_hurt != 25
			&& square_dist_mid(vec, curr->pos) < 0.5)
			return (true);
		curr = curr->next;
	}
	return (false);
}

void	collidex(t_vars *vars, t_player *player)
{
	int			side;
	t_cardinal	card;
	t_portal	*pt;

	side = floor(player->pos.x + player->motion.x);
	card = SOUTH;
	if (player->motion.x > 0)
		card = NORTH;
	if ((pt = get_portal(vars, side, floor(player->pos.y), card)))
		translate_portal_3(&(player->pos), card, pt);
	side = floor(player->pos.x + player->motion.x);
	if (!map_get(&vars->map, side, floor(player->pos.y)) && !collide_object(
		vars, player->pos.x + player->motion.x, player->pos.y, NULL))
		player->pos.x += player->motion.x;
	else
	{
		player->motion.x = 0;
		vars->bob = -0.04;
	}
}

void	collidey(t_vars *vars, t_player *player)
{
	int			side;
	t_cardinal	card;
	t_portal	*pt;

	side = floor(player->pos.y + player->motion.y);
	card = WEST;
	if (player->motion.y > 0)
		card = EAST;
	if ((pt = get_portal(vars, floor(player->pos.x), side, card)))
		translate_portal_3(&(player->pos), card, pt);
	side = floor(player->pos.y + player->motion.y);
	if (!map_get(&vars->map, floor(player->pos.x), side) && !collide_object(
		vars, player->pos.x, player->pos.y + player->motion.y, NULL))
		player->pos.y += player->motion.y;
	else
	{
		player->motion.y = 0;
		vars->bob = -0.04;
	}
}

void	add_nocollide(t_vars *vars, t_vecd *pos, t_vecd mov, t_sprite *s)
{
	if (collide_object(vars, pos->x, pos->y, s))
	{
		pos->x += mov.x;
		pos->y += mov.y;
		return ;
	}
	if (!map_get(&vars->map, floor(pos->x + mov.x), floor(pos->y)) &&
		!collide_object(vars, pos->x + mov.x, pos->y, s))
	{
		pos->x += mov.x;
	}
	if (!map_get(&vars->map, floor(pos->x), floor(pos->y + mov.y)) &&
		!collide_object(vars, pos->x, pos->y + mov.y, s))
	{
		pos->y += mov.y;
	}
}
