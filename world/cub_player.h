/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:57:35 by ttranche          #+#    #+#             */
/*   Updated: 2021/01/10 23:59:57 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PLAYER_H
# define CUB_PLAYER_H

# include "../utils/cub_vec.h"
# include "../utils/cub_keybinds.h"
# include "cub_map.h"
# include "cub_collide.h"
# include "cub_portal.h"

t_player	make_player();
void		update_motion(t_player *player, t_vars *vars);
bool		should_bob(t_player *player);

#endif
