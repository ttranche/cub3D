/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_goomba.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:58:07 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 11:52:11 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_GOOMBA_H
# define CUB_GOOMBA_H

# include "../cub.h"
# include "../world/cub_collide.h"
# include "cub_sprite_list.h"
# include "cub_doors.h"
# include "../pathfinder/cub_astar.h"

void	handle_goomba(t_sprite *curr, t_vars *vars);

#endif
