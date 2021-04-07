/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprites.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:51:21 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 11:54:57 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SPRITES_H
# define CUB_SPRITES_H

# include "../cub.h"
# include "../world/cub_collide.h"
# include "cub_sprite_list.h"
# include "cub_doors.h"
# include "cub_goomba.h"

typedef struct	s_sprite_r
{
	t_shape		draw;
	t_vec		v;
	t_vec		offset;
	int			color;
	t_vecd		pos;
	double		dist;
	double		sprite_angle;
	double		view_dist;
	float		dim;
}				t_sprite_r;

void			draw_sprites(t_vars *vars, bool skip);

#endif
