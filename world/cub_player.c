/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:58:22 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:20:44 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_player.h"

t_player	make_player(void)
{
	t_player player;

	player.pos.x = 0;
	player.pos.y = 0;
	player.pos.z = 0;
	player.s_pos.x = player.pos.x;
	player.s_pos.y = player.pos.y;
	player.motion.x = 0;
	player.motion.y = 0;
	player.motion.z = 0;
	player.health = 1;
	player.motion_yaw = 0;
	player.yaw = 0;
	player.pitch = -40;
	player.motion_yaw = 0;
	player.motion_pitch = 8;
	player.keybinds = make_keybinds();
	return (player);
}

void		handle_keys(t_player *player, bool bonus)
{
	float ratio;

	ratio = 0.88;
	if (player->keybinds.rotate_left && !player->keybinds.rotate_right)
		player->motion_yaw -= 0.012;
	else if (player->keybinds.rotate_right && !player->keybinds.rotate_left)
		player->motion_yaw += 0.012;
	else
		player->motion_yaw *= 0.895;
	if (player->keybinds.rotate_up && bonus)
		player->motion_pitch += 4;
	if (player->keybinds.rotate_down && bonus)
		player->motion_pitch -= 4;
	if (player->keybinds.jump && player->pos.z <= 0.0001 && bonus)
		player->motion.z = 0.128;
	if (player->keybinds.sneak && bonus)
		ratio *= 0.67;
	else if (player->pos.z > 0.001)
		ratio = 0.9;
	player->motion.x *= ratio;
	player->motion.y *= ratio;
}

bool		should_bob(t_player *player)
{
	if (player->pos.z >= 0.0001)
		return (false);
	if (player->keybinds.sneak)
		return (false);
	if (player->keybinds.forwards && !player->keybinds.backwards)
		return (true);
	if (player->keybinds.backwards && !player->keybinds.forwards)
		return (true);
	if (player->keybinds.left && !player->keybinds.right)
		return (true);
	if (player->keybinds.right && !player->keybinds.left)
		return (true);
	return (false);
}

void		update_render(t_player *player, t_vars *vars, bool bonus)
{
	player->render.x = player->pos.x;
	player->render.y = player->pos.y;
	player->render.z = player->pos.z;
	if (should_bob(player) && bonus)
		vars->bob = fmin(1, vars->bob + 0.04);
	else
		vars->bob = fmax(0, vars->bob - 0.04);
	play_sound_alt(vars->sounds.walk, should_bob(player)
		&& player->render.z == 0 && !player->keybinds.jump, true);
	if (player->keybinds.sneak && bonus)
		player->render.z -= 0.05;
	player->render.y += cos(vars->time / 6.0 + 34) * 0.01 * vars->bob;
	player->render.x += sin(vars->time / 4.8 + 56) * 0.01 * vars->bob;
	player->render.z += fabs(cos(vars->time / 7.5) * 0.03 * vars->bob);
	if (map_get(&vars->map, floor(player->render.x), floor(player->render.y)))
	{
		player->render.x = player->pos.x;
		player->render.y = player->pos.y;
	}
}

void		update_motion(t_player *player, t_vars *vars)
{
	double	cs;
	double	sn;
	t_vecd	move;

	move = player->keybinds.move;
	cs = cos(player->yaw);
	sn = sin(player->yaw);
	player->motion.x += move.x * cs - move.y * sn;
	player->motion.y += move.y * cs + move.x * sn;
	handle_keys(player, vars->bonus);
	player->motion.z *= 0.97;
	player->motion_yaw *= 0.914;
	player->motion_pitch *= 0.82;
	collidex(vars, player);
	collidey(vars, player);
	player->pos.z = fmin(fmax(0, player->pos.z + player->motion.z - .078), .42);
	update_render(player, vars, vars->bonus);
	player->yaw += player->motion_yaw;
	player->pitch = fmin(vars->resy / 4 - 4, fmax(-vars->resy / 4,
		player->pitch + player->motion_pitch));
	if (vars->shoot > 0)
		vars->shoot--;
}
