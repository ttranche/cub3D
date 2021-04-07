/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:17:54 by ttranche          #+#    #+#             */
/*   Updated: 2021/02/02 11:02:33 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_utils.h"

t_img	make_image(void *mlx, int w, int h)
{
	t_img	img;

	img.width = w;
	img.height = h;
	img.img = mlx_new_image(mlx, w, h);
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	img.pixel_len = img.bits_per_pixel / 8;
	return (img);
}

t_img	load_image(void *mlx, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &(img.width), &(img.height));
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	img.pixel_len = img.bits_per_pixel / 8;
	return (img);
}

void	set_strip(t_img *data, t_shape shape, int color)
{
	char	*dst;
	int		i;
	int		len;
	int		y;

	if (shape.x < 0)
		return ;
	y = shape.y;
	if (shape.y < 0)
		y = 0;
	i = 0;
	dst = data->addr + ((y - 1) *
		data->line_length + shape.x * (data->pixel_len));
	len = fmin(shape.height, data->height - y);
	while (i++ < len)
	{
		dst += data->line_length;
		*(unsigned int*)dst = color;
	}
}

void	set_img_strip(t_img *data, t_shape shape, float offset)
{
	t_vec		v;
	int			t;
	double		o;
	double		cur;
	char		*dst;

	if (shape.x < 0)
		return ;
	v.y = fmax(0, shape.y);
	v.x = (shape.img->width - 1) * offset;
	o = shape.img->height / (double)shape.height;
	cur = o * (v.y - shape.y);
	dst = data->addr + (v.y * data->line_length +
		shape.x * (data->pixel_len));
	while (v.y < shape.y + shape.height && v.y < data->height)
	{
		t = get_pixel(shape.img, v.x, (int)cur);
		if (shape.dim < 0.98)
			t = color_dim(t, shape.dim);
		*(unsigned int*)dst = t;
		dst += data->line_length;
		cur += o;
		++v.y;
	}
}

void	rect(t_img *data, t_shape shape, int color)
{
	int i;
	int j;
	int b;

	i = fmax(shape.x, 0);
	while (i < shape.x + shape.width && i < data->width)
	{
		j = fmax(shape.y, 0);
		while (j < shape.y + shape.height && j < data->height)
		{
			b = get_pixel(data, i, j);
			set_pixel(data, i, j, blend_colors(b, color));
			++j;
		}
		++i;
	}
}
