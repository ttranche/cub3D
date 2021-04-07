/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:38:52 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:20:44 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parser.h"

char	*read_arg(char *s1, char *s2, char **ret)
{
	while (*s1 && *s2)
	{
		if (*s2 == ' ')
		{
			s2++;
			continue;
		}
		if (*s1 != *s2)
			return (0);
		s2++;
		s1++;
	}
	if (*s1 == 0 && *s2 == ' ')
	{
		while (*s2 == ' ')
			s2++;
		truncate_str(s2);
		*ret = s2;
		return (s2);
	}
	return (0);
}

bool	read_argument_sounds(t_vars *vars, t_line *file)
{
	char *arg;

	if (read_arg("S_DOOR", file->line, &arg))
		set_sound(&(vars->sounds.door), vars, arg);
	else if (read_arg("S_HURT", file->line, &arg))
		set_sound(&(vars->sounds.hurt), vars, arg);
	else if (read_arg("S_STOMP", file->line, &arg))
		set_sound(&(vars->sounds.stomp), vars, arg);
	else if (read_arg("S_PORTAL", file->line, &arg))
		set_sound(&(vars->sounds.portal), vars, arg);
	else if (read_arg("S_HEAL", file->line, &arg))
		set_sound(&(vars->sounds.heal), vars, arg);
	else if (read_arg("S_AMBIENT", file->line, &arg))
		set_sound(&(vars->sounds.ambient), vars, arg);
	else if (read_arg("S_WALK", file->line, &arg))
		set_sound(&(vars->sounds.walk), vars, arg);
	else
		return (false);
	return (true);
}

bool	read_argument_custom(t_vars *vars, t_line *file)
{
	char *arg;

	if (read_arg("FLOOR", file->line, &arg))
		set_texture(&(vars->floor), vars, arg);
	else if (read_arg("GOOMBA", file->line, &arg))
		set_texture(&(vars->goomba_img), vars, arg);
	else if (read_arg("PORTAL", file->line, &arg))
		set_texture(&(vars->portal), vars, arg);
	else if (read_arg("DOOR", file->line, &arg))
		set_texture(&(vars->door_img), vars, arg);
	else if (read_arg("HK", file->line, &arg))
		set_texture(&(vars->health_img), vars, arg);
	else if (read_arg("SKYBOX", file->line, &arg)
		&& vars->resx > 0 && vars->resy > 0)
		make_skybox(vars, &(vars->skybox), arg);
	else if (read_arg("GUN", file->line, &arg))
		make_gun(vars, &(vars->gun), arg);
	else if (read_arg("DASH", file->line, &arg))
		make_dash(vars, &(vars->dash), arg);
	else
		return (read_argument_sounds(vars, file));
	return (true);
}

bool	read_argument(t_vars *vars, t_line *file)
{
	char *arg;

	if (read_arg("R", file->line, &arg))
		set_resolution(vars, arg);
	else if (read_arg("S", file->line, &arg))
		set_texture(&(vars->sprite_img), vars, arg);
	else if (read_arg("NO", file->line, &arg))
		set_texture(&(vars->walls.north), vars, arg);
	else if (read_arg("SO", file->line, &arg))
		set_texture(&(vars->walls.south), vars, arg);
	else if (read_arg("WE", file->line, &arg))
		set_texture(&(vars->walls.west), vars, arg);
	else if (read_arg("EA", file->line, &arg))
		set_texture(&(vars->walls.east), vars, arg);
	else if (read_arg("F", file->line, &arg))
		set_color(vars, &(vars->bottom_color), arg);
	else if (read_arg("C", file->line, &arg))
		set_color(vars, &(vars->top_color), arg);
	else if (vars->bonus)
		return (read_argument_custom(vars, file));
	else
		return (false);
	return (true);
}
