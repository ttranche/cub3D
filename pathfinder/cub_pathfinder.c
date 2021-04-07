/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_pathfinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:59:35 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 10:59:40 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_pathfinder.h"

void	refresh_pathfinding(t_vars *vars)
{
	t_vec	startp;

	if (vars->time % 60 != 0)
		return ;
	if (vars->pathfinder.x == -1)
		return ;
	startp.x = floor(vars->player.pos.x);
	startp.y = floor(vars->player.pos.y);
	if (vars->last_path)
		free(vars->last_path);
	vars->last_path = astar(&vars->map, startp, vars->pathfinder, 2000);
}
