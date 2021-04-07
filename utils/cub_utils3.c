/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:25:19 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 12:21:05 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_utils.h"

void	set_big_pixel(t_img *d, int x, int y, int color)
{
	int	addr;

	addr = (y * d->line_length + x * d->pixel_len);
	*(unsigned int*)(d->addr + addr) = color;
	if (x < d->width - 1 && y < d->height - 1)
		*(unsigned int*)(d->addr + addr + d->pixel_len +
			d->line_length) = color;
	if (y < d->height - 1)
		*(unsigned int*)(d->addr + addr + d->line_length) = color;
	if (x < d->width - 1)
		*(unsigned int*)(d->addr + addr + d->pixel_len) = color;
}

int		color_dim(int color, float ratio)
{
	int r;
	int g;
	int b;

	r = (int)(((color & 0xff0000) >> 16) * ratio);
	g = (int)(((color & 0xff00) >> 8) * ratio);
	b = (int)((color & 0xff) * ratio);
	return (r << 16 | g << 8 | b);
}

void	set_portal_strip(t_img *d, t_shape shape, t_img *tex, float offset)
{
	t_vec		v;
	int			t;
	double		o;
	double		cur;
	char		*dst;

	v.y = fmax(0, shape.y);
	v.x = (shape.img->width - 1) * offset;
	o = shape.img->height / (double)shape.height;
	cur = o * (v.y - shape.y);
	dst = d->addr + ((v.y - 1) * d->line_length + shape.x * (d->pixel_len));
	while (++v.y <= shape.y + shape.height && v.y < d->height)
	{
		t = get_pixel(tex, v.x, cur);
		dst += d->line_length;
		cur += o;
		if (t == 0)
			continue ;
		if (t == 0x00FFFFFF)
			t = get_pixel(shape.img, v.x, cur - o);
		if (shape.dim < 0.98)
			t = color_dim(t, shape.dim);
		*(unsigned int*)dst = t;
	}
}

void	e_portal_strip(t_img *data, t_shape shape, t_img *tex, float offset)
{
	int		y;
	int		x;
	int		t;
	int		o;

	if (shape.x < 0)
		return ;
	y = fmax(0, shape.y);
	x = (tex->width - 1) * offset;
	if (shape.dim <= 0.01)
		return ;
	while (y < shape.y + shape.height && y < data->height)
	{
		o = (int)((y - shape.y) / (double)shape.height * tex->height);
		t = get_pixel(tex, x, o);
		y++;
		if (t == 0x00FFFFFF)
			t = get_pixel(shape.img, x, o);
		if (shape.dim < 0.98)
			t = color_dim(t, shape.dim);
		set_pixel(data, shape.x, y - 1, t);
	}
}

double	modabs(double d)
{
	double a;

	a = fmod(d, 1);
	if (d < 0)
		return (1 - fabs(a));
	return (a);
}
