/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:21:50 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:30:34 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdbool.h>
# include <stdlib.h>
# include <math.h>

# include "utils/cub_vec.h"
# include "utils/cub_rot.h"
# include "utils/cub_utils.h"
# include "render/cub_blur.h"
# include "world/cub_map.h"
# include "utils/cub_line_reader.h"
# include "other/cub_sound.h"
# include "include/cub_sprite_type.h"
# include "include/cub_cardinal_enum.h"
# include "include/cub_keybinds_struct.h"
# include "include/cub_sprite_struct.h"
# include "include/cub_player_struct.h"
# include "include/cub_raycast_struct.h"
# include "include/cub_mouseover_struct.h"
# include "include/cub_floor_render.h"
# include "include/cub_walls.h"
# include "include/bmp_partial_alligned_header.h"

typedef struct		s_vars {
	void			*mlx;
	void			*win;
	t_img			img;
	t_player		player;
	t_blur			blur;
	t_map			map;
	t_sprite		*sprites;
	double			resx;
	double			resy;
	t_line			*file;
	t_walls			walls;
	t_img			floor;
	t_img			portal;
	t_img			skybox;
	t_img			gun;
	t_img			dash;
	t_img			sprite_img;
	t_img			health_img;
	t_img			goomba_img;
	t_img			door_img;
	t_portal		*first_portal;
	t_portal		*second_portal;
	double			fov;
	double			cam_width;
	double			*depth;
	int				shoot;
	int				time;
	int				top_color;
	int				bottom_color;
	int				render_distance;
	bool			should_dim;
	t_vec			*last_path;
	t_vec			pathfinder;
	float			bob;
	bool			bonus;
	bool			bmp;
	t_sounds		sounds;
	unsigned long	delay;
}					t_vars;

int					render_next_frame(t_vars *vars);

#endif
