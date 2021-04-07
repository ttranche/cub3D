/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_blur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:31:12 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/20 14:52:01 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_blur.h"

/*
** Applys the kernel to each pixel
*/

void	blur_math(t_blur b, t_img *new, int color, bool yb)
{
	int i;
	int j;
	int current;

	i = -b.kernel_size;
	color = 0x00000000;
	while (i < b.kernel_size)
	{
		if (yb)
			current = get_pixel(&(b.src), b.shape.x + b.x, fmax(b.shape.y,
			fmin(b.src.height - 1, b.shape.y + b.y + i * b.opt)));
		else
			current = get_pixel(&(b.src), fmax(b.shape.x, fmin(b.src.width
			- 1, b.shape.x + b.x + i * b.opt)), b.shape.y + b.y);
		color = color_add(current, color, b.kernel[b.kernel_size + i++]);
	}
	i = 0;
	while (i < b.opt)
	{
		j = 0;
		while (j < b.opt)
			set_pixel(new, b.x + i, b.y + j++, color);
		++i;
	}
}

/*
** Recursive function which applys the kernel horizontaly then calls itself back
** to blur verticaly
*/

t_img	make_blur_opt(t_blur blur, bool yb)
{
	t_img		new;

	blur.y = 0;
	new = blur.temp;
	while (blur.y < new.height)
	{
		blur.x = 0;
		while (blur.x < new.width)
		{
			blur_math(blur, &new, 0, yb);
			blur.x += blur.opt;
		}
		blur.y += blur.opt;
	}
	if (yb)
		return (new);
	blur.shape.x = 0;
	blur.shape.y = 0;
	blur.src = blur.temp;
	blur.temp = blur.dest;
	return (make_blur_opt(blur, true));
}

/*
** Fills the kernel values
*/

void	fill_kernel(t_blur *s)
{
	s->kernel[0] = 0.0013316424;
	s->kernel[1] = 0.0031311892;
	s->kernel[2] = 0.006728909;
	s->kernel[3] = 0.013215798;
	s->kernel[4] = 0.02372224;
	s->kernel[5] = 0.038916297;
	s->kernel[6] = 0.0583473;
	s->kernel[7] = 0.07995093;
	s->kernel[8] = 0.10012437;
	s->kernel[9] = 0.11459602;
	s->kernel[10] = 0.119870625;
	s->kernel[11] = 0.11459602;
	s->kernel[12] = 0.10012437;
	s->kernel[13] = 0.07995093;
	s->kernel[14] = 0.0583473;
	s->kernel[15] = 0.038916297;
	s->kernel[16] = 0.02372224;
	s->kernel[17] = 0.013215798;
	s->kernel[18] = 0.006728909;
	s->kernel[19] = 0.0031311892;
	s->kernel[20] = 0.0013316424;
}

/*
** Creates the blur buffers and sets up some stuff
*/

t_blur	make_blur_struct(void *mlx, t_img orig, t_shape shape)
{
	t_blur	blur;

	blur.mlx = mlx;
	blur.src = orig;
	blur.temp = make_image(mlx, shape.width, shape.height);
	blur.dest = make_image(mlx, shape.width, shape.height);
	blur.shape = shape;
	blur.opt = 5;
	blur.x = 0;
	blur.y = 0;
	blur.kernel_size = 10;
	fill_kernel(&blur);
	return (blur);
}
