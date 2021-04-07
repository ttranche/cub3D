/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hud.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:28:51 by ttranche          #+#    #+#             */
/*   Updated: 2021/02/01 22:30:36 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_HUD_H
# define CUB_HUD_H

# include "../cub.h"
# include "cub_minimap.h"
# include "cub_xquartz_layer.h"

void	draw_hud(t_vars *vars);
void	draw_death(t_vars *vars);
void	draw_cursor(t_vars *vars);
void	render_hand(t_vars *vars);
void	draw_skybox(t_vars *vars);

#endif
