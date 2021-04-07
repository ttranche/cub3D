/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:02:43 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:25:55 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SPRITE_STRUCT_H
# define CUB_SPRITE_STRUCT_H

# include "cub_sprite_type.h"

typedef struct		s_sprite
{
	t_sprite_k		kind;
	t_vecd			pos;
	t_img			*texture;
	int				last_hurt;
	bool			dead;
	int				path_index;
	t_vec			*path;
	struct s_sprite	*next;
}					t_sprite;

#endif
