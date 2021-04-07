/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:38:17 by ttranche          #+#    #+#             */
/*   Updated: 2021/01/30 14:14:41 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSER_H
# define CUB_PARSER_H

# include "../cub.h"
# include "cub_setter.h"
# include "../render/cub_texture.h"

bool	read_argument_sounds(t_vars *vars, t_line *file);
bool	read_argument_custom(t_vars *vars, t_line *file);
bool	read_argument(t_vars *vars, t_line *file);

#endif
