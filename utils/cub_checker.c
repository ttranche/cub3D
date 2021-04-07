/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:55:24 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/24 09:55:42 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_checker.h"

void	check_textures_custom(t_vars *vars)
{
	if (!vars->skybox.img)
		handle_warning(vars, "Missing skybox texture, using color instead.");
	if (!vars->gun.img)
		handle_warning(vars, "Missing gun texture, hiding it.");
	if (!vars->dash.img)
		handle_warning(vars, "Missing dashboard overlay texture, ignoring.");
	if (!vars->floor.img)
		handle_warning(vars, "Missing floor texture, using color instead.");
	if (!vars->door_img.img)
		handle_error(vars, "Missing door texture.", "DOOR [.xpm]");
	if (!vars->portal.img)
		handle_warning(vars, "Missing portal texture, disabling them.");
	if (!vars->goomba_img.img)
		handle_error(vars, "Missing goomba texture.", "GOOMBA [.xpm]");
	if (!vars->health_img.img)
		handle_error(vars, "Missing health kit texture.", "HK [.xpm]");
	if (vars->walls.north.width != vars->portal.width ||
		vars->walls.north.height != vars->portal.height ||
		vars->walls.south.width != vars->portal.width ||
		vars->walls.south.height != vars->portal.height ||
		vars->walls.west.width != vars->portal.width ||
		vars->walls.west.height != vars->portal.height ||
		vars->walls.east.width != vars->portal.width ||
		vars->walls.east.height != vars->portal.height)
		handle_error(vars, "Portal and wall texture sizes differ!", NULL);
}

void	check_textures(t_vars *vars)
{
	if (!vars->sprite_img.img)
		handle_error(vars, "Missing sprite texture.", NULL);
	if (!vars->walls.north.img)
		handle_error(vars, "Missing north wall texture.", NULL);
	if (!vars->walls.south.img)
		handle_error(vars, "Missing south wall texture.", NULL);
	if (!vars->walls.west.img)
		handle_error(vars, "Missing west wall texture.", NULL);
	if (!vars->walls.east.img)
		handle_error(vars, "Missing east wall texture.", NULL);
}

void	check_define(t_vars *vars)
{
	if (vars->resx <= 0 || vars->resy <= 0)
		handle_error(vars, "Resolution not properly set.", NULL);
	if (vars->resx > 5218 || vars->resy > 5218)
		handle_error(vars, "Resolution too big for mlx...", NULL);
	if ((unsigned int)(vars->top_color) == 0xDB000000)
		handle_error(vars, "Ceeling color not set.", NULL);
	if ((unsigned int)(vars->bottom_color) == 0xDB000000)
		handle_error(vars, "Bottom color not set.", NULL);
	if (vars->player.health == 0x0)
		handle_error(vars, "Player not set.", NULL);
	check_textures(vars);
	if (vars->bonus)
		check_textures_custom(vars);
}
