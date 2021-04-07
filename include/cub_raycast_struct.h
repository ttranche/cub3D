/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:08:46 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:28:14 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_RAYCAST_STRUCT_H
# define CUB_RAYCAST_STRUCT_H

# include "../utils/cub_vec.h"
# include "../utils/cub_utils.h"
# include "cub_cardinal_enum.h"
# include "cub_portal_struct.h"

typedef struct		s_ray {
	t_vecd			st_cos;
	t_vecd			st_sin;
	double			ln_cos;
	double			ln_sin;
}					t_ray;

typedef struct		s_trace {
	t_ray			ray;
	t_ray			step;
	t_rot			rot;
	t_shape			line;
	t_vec			pos;
	t_vecd			ref;
	t_portal_render *portal;
	t_cardinal		card;
	t_portal		*pt;
	int				i;
	double			newa;
	double			len;
	double			offset;
}					t_trace;

#endif
