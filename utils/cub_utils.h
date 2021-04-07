/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:11:39 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/20 14:54:40 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_UTILS_H
# define CUB_UTILS_H

# include <mlx.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
# include "cub_vec.h"

typedef struct	s_img
{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			pixel_len;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_shape
{
	int			x;
	int			y;
	int			width;
	int			height;
	bool		mirror;
	double		dim;
	t_img		*img;
}				t_shape;

void			set_pixel(t_img *data, int x, int y, int color);
void			set_big_pixel(t_img *d, int x, int y, int color);
int				get_pixel(t_img *data, int x, int y);
int				color_add(int color, int current, float ratio);
t_img			make_image(void *mlx, int w, int h);
t_img			load_image(void *mlx, char *path);
void			rect(t_img *data, t_shape shape, int color);
void			set_strip(t_img *data, t_shape shape, int color);
void			set_img_strip(t_img *data, t_shape shape, float offset);
void			set_portal_strip(t_img *data, t_shape shape, t_img *tex,
					float offset);
int				color_dim(int color, float ratio);
void			e_portal_strip(t_img *data, t_shape shape, t_img *tex,
					float offset);
double			modabs(double d);
void			fill_img(t_img img, int c, int start, int stop);
int				blend_colors(int o, int n);
double			ease_in_out(double t);
void			swap_d(double *a, double *b);
double			distance(t_vecd v);
double			get_angdist(double a, double b);
void			*make_closedmap(int size);
int				stringlen(char *string);
void			truncate_str(char *s);
int				bad_strncmp(const char *s1, const char *s2, size_t n);
bool			check_iscub(char *file);

#endif
