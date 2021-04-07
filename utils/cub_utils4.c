/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 22:51:58 by ttranche          #+#    #+#             */
/*   Updated: 2021/02/01 23:08:41 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_utils.h"

void	fill_img(t_img img, int c, int start, int stop)
{
	int *bytes;
	int *end;

	end = (void *)img.addr + stop * img.line_length;
	bytes = (int *)((void*)img.addr + start * img.line_length);
	while (bytes < end)
		*bytes++ = c;
}

int		blend_colors(int o, int n)
{
	float	a;
	int		r;
	int		g;
	int		b;

	a = 1 - ((n >> 24) & 0xFF) / 255.0f;
	if (a == 1)
		return (n);
	r = (int)(((o & 0xff0000) >> 16) * (1 - a) + ((n & 0xff0000) >> 16) * a);
	g = (int)(((o & 0xff00) >> 8) * (1 - a) + ((n & 0xff00) >> 8) * a);
	b = (int)((o & 0xff) * (1 - a) + (n & 0xff) * a);
	return (0 << 24 | r << 16 | g << 8 | b);
}

double	distance(t_vecd v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

double	get_angdist(double a, double b)
{
	return (atan2(sin(a - b), cos(a - b)));
}

void	swap_d(double *a, double *b)
{
	double temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
