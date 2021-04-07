/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bitmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:43:58 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:20:44 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bitmap.h"

/*
**	Assuming the compiler used uses the int/short sizes standards (32bits)
**
**	char[2]		signature; // 0 -> 1
**	int			size; // 2 -> 5
**	int			reserved; // 6 -> 9
**	int			footer_offset; // 10 -> 13
**	int			header_size; // 14 -> 17
**	int			width; // 18 -> 21
**	int			height; // 22 -> 25
**	short		planes; // 26 -> 27 (1?)
**	short		bit_count; // 28 -> 29
**	int			compression; // 30 -> 33
**	int			images_size; // 34 -> 37
**	int			x_res; // 38 -> 41
**	int			y_res; // 42 -> 45
**	int			colors_used; // 46 -> 49
**	int			important_colors; // 50 -> 53
*/

t_bmp_partial_alligned_header	get_generic_header(int width, int height)
{
	t_bmp_partial_alligned_header	h;
	int								size;

	size = 54;
	bad_bzero(&h, sizeof(t_bmp_partial_alligned_header));
	h.width = width;
	h.height = height;
	h.planes_bc = 0x00180001;
	h.size = size + (3) * (width * height);
	h.footer_offset = size;
	h.header_size = size - 14;
	return (h);
}

void							*bad_bzero(void *o, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)o;
	while (i < len)
		dst[i++] = 0;
	return (o);
}

int								render_and_save(t_vars *vars)
{
	t_bmp_partial_alligned_header	header;
	t_vec							pos;
	int								color;
	int								fd;

	render_next_frame(vars);
	fd = open("./render.bmp", O_WRONLY | O_CREAT, 0666);
	header = get_generic_header(vars->resx, vars->resy);
	write(fd, "BM", 2);
	write(fd, &header, 52);
	pos.y = vars->resy;
	while (--pos.y >= 0)
	{
		pos.x = 0;
		while (pos.x < vars->resx)
		{
			color = get_pixel(&vars->img, pos.x++, pos.y);
			write(fd, &color, 3);
		}
		color = 0;
		write(fd, &color, (4 - ((int)vars->resx * 3) % 4) % 4);
	}
	return (1);
}
