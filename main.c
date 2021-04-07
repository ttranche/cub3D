/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:12:18 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/24 11:23:50 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	update_world(t_vars *vars)
{
	update_keybinds(vars);
	if (vars->bonus)
	{
		get_delay(true, 16666, !LINUX);
		while (vars->delay > 16666)
		{
			update_motion(&(vars->player), vars);
			draw_sprites(vars, true);
			vars->time++;
			vars->delay -= 16666;
			refresh_pathfinding(vars);
		}
	}
	update_motion(&(vars->player), vars);
	refresh_pathfinding(vars);
}

int		render_next_frame(t_vars *vars)
{
	if (vars->player.health <= 0)
		draw_death(vars);
	else
	{
		update_world(vars);
		draw_floor(vars);
		if (!vars->bmp)
			draw_skybox(vars);
		ray(vars, &(vars->img));
		draw_sprites(vars, false);
		if (!vars->bmp)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
			draw_cursor(vars);
			draw_hud(vars);
			render_hand(vars);
		}
		if (vars->bonus)
			vars->delay += get_delay(false, 16666, !LINUX);
		vars->time++;
	}
	mlx_do_sync(vars->mlx);
	return (0);
}

void	setup_render(t_vars *vars)
{
	t_shape shape;

	vars->fov = (double)vars->resy / (double)vars->resx;
	vars->cam_width = (1 / (cos(atan2(-0.5, vars->fov))));
	vars->img = make_image(vars->mlx, vars->resx, vars->resy);
	if (!vars->bonus || ((!vars->floor.img && vars->bottom_color != 0)
		|| (!vars->skybox.img && vars->top_color != 0)))
	{
		vars->should_dim = false;
		vars->render_distance = 50;
	}
	vars->depth = malloc(sizeof(double) * vars->resx);
	if (!vars->depth)
		handle_error(vars, "Failed to allocate depth buffer.", NULL);
	shape.width = 210;
	shape.height = 150;
	shape.x = 20;
	shape.y = vars->resy - shape.height - 45;
	vars->blur = make_blur_struct(vars->mlx, vars->img, shape);
}

void	load_args(int argc, char **argv, t_vars *vars)
{
	if (argc >= 2 && argc <= 3)
	{
		if (argc == 3)
		{
			vars->bmp = bad_strncmp(argv[2], "--save", 6) == 0;
			if (!vars->bmp)
				handle_error(vars, "Unknown options", argv[2]);
		}
		if (!check_iscub(argv[1]))
			handle_error(vars, "Unknown file type.", argv[1]);
		load_f(argv[1], vars);
	}
	else
		handle_error(vars, "Usage: cub3D [cub file] [--save]", NULL);
}

int		main(int argc, char **argv)
{
	t_vars	vars;

	init_default(&vars);
	set_bonus(&(vars.bonus));
	vars.mlx = mlx_init();
	if (!vars.mlx)
		handle_error(&vars, "Failed to initialize mlx.", NULL);
	load_args(argc, argv, &vars);
	check_define(&vars);
	setup_render(&vars);
	if (vars.bmp)
	{
		vars.player.pitch = 0;
		render_and_save(&vars);
		clean_and_exit(0, &vars);
	}
	vars.win = mlx_new_window(vars.mlx, vars.resx, vars.resy, "Cub3D");
	if (vars.sounds.ambient)
		play_sound_alt(vars.sounds.ambient, true, true);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_lift, &vars);
	mlx_hook(vars.win, LINUX ? 33 : 17, 1L << 17, clean_and_exit_z, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
