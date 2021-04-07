/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_setter.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:46:18 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 12:06:05 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MAP_SETTER_H
# define CUB_MAP_SETTER_H

# include "../cub.h"
# include "../world/cub_player.h"
# include "../utils/cub_error.h"
# include "../sprites/cub_sprites.h"

int		set_player(t_vars *vars, char c, t_vec p);
int		set_sprite(t_vars *vars, char c, t_vec p);
int		set_entity(t_vars *vars, char c, t_vec p);
int		set_pathfinder(t_vars *vars, char c, t_vec p);

#endif
