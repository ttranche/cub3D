/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:34:12 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 11:09:42 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_texture.h"

/*
** Creates the skybox t_img based on the screen size
*/

t_img	make_skybox(t_vars *vars, t_img *img, char *path)
{
	t_img	temp;
	t_img	skybox;
	t_vec	p;
	t_vec	of;

	temp = load_image(vars->mlx, path);
	if (!temp.img)
		return (*img = temp);
	skybox = make_image(vars->mlx, vars->resx * 3.14, vars->resy);
	if (skybox.img)
	{
		p.x = -1;
		while (++p.x < skybox.width)
		{
			p.y = -1;
			of.x = ((double)p.x / skybox.width) * temp.width;
			while (++p.y < skybox.height)
			{
				of.y = ((double)p.y / skybox.height) * temp.height;
				set_pixel(&skybox, p.x, p.y, get_pixel(&temp, of.x, of.y));
			}
		}
	}
	destroy_img(vars, &temp);
	return (*img = skybox);
}

/*
** Creates the gun t_img overlay and makes it transparent
*/

t_img	make_gun(t_vars *vars, t_img *img, char *path)
{
	t_img	gun;
	t_vec	p;
	int		color;

	gun = load_image(vars->mlx, path);
	if (!gun.img)
		return (*img = gun);
	p.x = 0;
	while (p.x < gun.width)
	{
		p.y = 0;
		while (p.y < gun.height)
		{
			color = get_pixel(&gun, p.x, p.y);
			if (color == 0x00FFFFFF)
				set_pixel(&gun, p.x, p.y, 0xFF000000);
			p.y++;
		}
		p.x++;
	}
	return (*img = gun);
}

/*
** Creates the dashboard shadow by loading a grayscale image and shifting
** its bytes to the left to make an alpha mask
*/

t_img	make_dash(t_vars *vars, t_img *img, char *path)
{
	t_img	dash;
	t_vec	p;
	int		color;

	dash = load_image(vars->mlx, path);
	p.x = 0;
	while (p.x < dash.width)
	{
		p.y = 0;
		while (p.y < dash.height)
		{
			color = (get_pixel(&dash, p.x, p.y) & 0xFF);
			if (LINUX)
				color = (int)((char)color * 1.8f) & 0xFF;
			set_pixel(&dash, p.x, p.y, color << 24);
			p.y++;
		}
		p.x++;
	}
	return (*img = dash);
}
