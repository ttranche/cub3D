/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:51:51 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/24 11:23:44 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_cleaner.h"

void	destroy_img(t_vars *vars, t_img *img)
{
	if (img->img)
	{
		mlx_destroy_image(vars->mlx, img->img);
		img->img = NULL;
	}
}

void	clean_images(t_vars *vars)
{
	destroy_img(vars, &(vars->walls.north));
	destroy_img(vars, &(vars->walls.south));
	destroy_img(vars, &(vars->walls.west));
	destroy_img(vars, &(vars->walls.east));
	destroy_img(vars, &(vars->floor));
	destroy_img(vars, &(vars->portal));
	destroy_img(vars, &(vars->skybox));
	destroy_img(vars, &(vars->gun));
	destroy_img(vars, &(vars->dash));
	destroy_img(vars, &(vars->sprite_img));
	destroy_img(vars, &(vars->health_img));
	destroy_img(vars, &(vars->goomba_img));
	destroy_img(vars, &(vars->door_img));
	destroy_img(vars, &(vars->img));
	destroy_img(vars, &(vars->blur.dest));
	destroy_img(vars, &(vars->blur.temp));
	empty_sprites(&(vars->sprites));
}

void	clean_all(t_vars *vars)
{
	clean_images(vars);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (LINUX)
		mlx_destroy_display(vars->mlx);
	clear_map(&(vars->map));
	clear_sounds(&(vars->sounds));
	free_file(&vars->file);
	if (vars->depth)
		free(vars->depth);
	if (vars->mlx)
		free(vars->mlx);
	if (vars->last_path)
		free(vars->last_path);
}

void	clean_and_exit(int code, t_vars *vars)
{
	clean_all(vars);
	vars = NULL;
	exit(code);
}

int		clean_and_exit_z(t_vars *vars)
{
	clean_and_exit(0, vars);
	return (0);
}
