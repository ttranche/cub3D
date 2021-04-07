/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_floor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 22:45:34 by ttranche          #+#    #+#             */
/*   Updated: 2021/01/11 00:02:49 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FLOOR_H
# define CUB_FLOOR_H

# include "../cub.h"

void	setup_floor(t_vars *vars, t_floor_render *f);
void	draw_floor(t_vars *vars);
void	render_row_floor(t_vars *vars, t_floor_render *f);

#endif
