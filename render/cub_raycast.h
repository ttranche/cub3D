/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:11:13 by ttranche          #+#    #+#             */
/*   Updated: 2021/01/30 19:51:39 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_RAYCAST_H
# define CUB_RAYCAST_H

# include "../cub.h"
# include "../world/cub_cardinal.h"
# include "../world/cub_portal.h"
# include "../utils/cub_vec.h"

void			ray(t_vars *vars, t_img *img);
t_vec			get_collide_pos(t_trace trace);
t_mouseover		get_mouseover(t_vars *vars);
int				check_colide(t_vars *vars, t_vec pos);
void			render_portal(t_shape line, float offset, t_vars *vars);
t_ray			get_init_ray(t_rot *rot, double x, double y);
void			cast_forward(t_ray *ray, t_ray step);
t_img			*get_texture(t_vars *vars, t_cardinal card);

#endif
