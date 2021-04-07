/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_portal2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:29:28 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 12:22:57 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_portal.h"

void	translate_portal(t_vecd *ref, t_cardinal card, t_portal *pt)
{
	t_vec vec;

	ref->x += (pt->link->pos.x - pt->pos.x);
	ref->y += (pt->link->pos.y - pt->pos.y);
	if (get_opposite(card) == pt->link->card)
	{
		vec = get_direction(card);
		ref->x += vec.x;
		ref->y += vec.y;
	}
}

void	translate_portal_3(t_vec3d *ref, t_cardinal card, t_portal *pt)
{
	t_vec vec;

	ref->x += (pt->link->pos.x - pt->pos.x);
	ref->y += (pt->link->pos.y - pt->pos.y);
	if (get_opposite(card) == pt->link->card)
	{
		vec = get_direction(card);
		ref->x += vec.x;
		ref->y += vec.y;
	}
}

void	handle_portal_creation(t_vars *vars)
{
	t_mouseover over;

	over = get_mouseover(vars);
	if (vars->first_portal && !vars->second_portal)
		if (over.card != get_opposite(vars->first_portal->card))
		{
			free(vars->first_portal);
			vars->first_portal = NULL;
		}
	if (vars->first_portal && vars->second_portal)
	{
		free(vars->first_portal);
		free(vars->second_portal);
		vars->first_portal = NULL;
		vars->second_portal = NULL;
	}
	if (over.found)
		if (create_portal(vars, over.pos.x, over.pos.y, over.card))
			vars->shoot = 50;
}
