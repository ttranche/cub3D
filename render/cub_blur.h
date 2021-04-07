/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_blur.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:33:53 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 11:03:56 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BLUR_H
# define CUB_BLUR_H

# include "../utils/cub_utils.h"

typedef struct	s_blur
{
	void		*mlx;
	t_img		src;
	t_img		temp;
	t_img		dest;
	t_shape		shape;
	int			opt;
	int			x;
	int			y;
	int			i;
	double		kernel[21];
	int			kernel_size;
}				t_blur;

t_img			make_blur(t_img *data, void *mlx, bool yb);
t_blur			make_blur_struct(void *mlx, t_img orig, t_shape shape);
t_img			make_blur_opt(t_blur blur, bool yb);

#endif
