/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:45:39 by ttranche          #+#    #+#             */
/*   Updated: 2021/01/30 14:14:01 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MAP_PARSER_H
# define CUB_MAP_PARSER_H

# include "../cub.h"
# include "cub_map_setter.h"
# include "../utils/cub_error.h"

t_vec	get_map_size(t_line *start);
int		set_map(t_vars *vars, char c, t_vec p);
void	handle_door_rotation(t_vars *vars);
bool	is_map_valid(t_map *map);

#endif
