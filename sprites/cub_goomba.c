/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_goomba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:57:48 by ttranche          #+#    #+#             */
/*   Updated: 2021/01/28 22:59:04 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_goomba.h"

void	refresh_path(t_sprite *curr, t_vars *vars, int maxtries)
{
	t_vec	startp;
	t_vec	endp;
	t_vec	*new;

	startp.x = floor(curr->pos.x);
	startp.y = floor(curr->pos.y);
	endp.x = floor(vars->player.pos.x);
	endp.y = floor(vars->player.pos.y);
	new = astar(&vars->map, startp, endp, maxtries);
	if (new)
	{
		if (curr->path)
			free(curr->path);
		curr->path = new;
		curr->path_index = 0;
	}
}

t_vec3d	get_next_move(t_sprite *curr, t_vars *vars)
{
	t_vec	dest;
	t_vec3d	ret;

	while (curr->path)
	{
		dest = curr->path[curr->path_index];
		if (dest.x == -999 && dest.y == -999)
		{
			free(curr->path);
			curr->path = NULL;
			curr->path_index = 0;
		}
		else if (dist2di(curr->pos, dest) < 0.55 && ++curr->path_index)
			continue ;
		ret.x = dest.x + 0.5;
		ret.y = dest.y + 0.5;
		return (ret);
	}
	if (square_dist(vars->player.pos, curr->pos) > 9)
	{
		ret.x = curr->pos.x;
		ret.y = curr->pos.y;
		return (ret);
	}
	return (vars->player.pos);
}

void	handle_action(t_vars *vars, t_sprite *curr, t_vecd mov)
{
	if (curr->last_hurt > 20 && vars->player.pos.z >
		0.11 && vars->player.motion.z < 0.085)
	{
		curr->dead = true;
		vars->player.motion.z += 0.025;
		free(curr->path);
		curr->path = NULL;
		curr->path_index = 0;
		play_sound(vars->sounds.stomp);
	}
	else
	{
		normalize(&mov, 0.2);
		vars->player.motion.x += mov.x;
		vars->player.motion.y += mov.y;
		vars->player.motion.z = 0.12;
		vars->player.health -= 0.101;
		curr->last_hurt = 0;
		play_sound(vars->sounds.hurt);
	}
}

void	handle_goomba(t_sprite *curr, t_vars *vars)
{
	t_vecd	mov;
	t_vec3d	next;

	if (curr->last_hurt % 1000 == 20)
		refresh_path(curr, vars, 350);
	else if (curr->last_hurt % 70 == 0)
		refresh_path(curr, vars, 250);
	next = get_next_move(curr, vars);
	curr->last_hurt++;
	mov.x = (next.x - curr->pos.x);
	mov.y = (next.y - curr->pos.y);
	normalize(&mov, 0.04);
	if (square_dist(vars->player.pos, curr->pos) < 0.14 && curr->last_hurt > 50)
		handle_action(vars, curr, mov);
	add_nocollide(vars, &curr->pos, mov, curr);
}
