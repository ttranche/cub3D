/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keybinds_struct.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:00:10 by ttranche          #+#    #+#             */
/*   Updated: 2021/01/31 14:01:01 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_KEYBINDS_STRUCT_H
# define CUB_KEYBINDS_STRUCT_H

# include "../utils/cub_vec.h"

typedef struct		s_keybinds
{
	bool			forwards;
	bool			backwards;
	bool			left;
	bool			right;
	bool			rotate_left;
	bool			rotate_right;
	bool			rotate_up;
	bool			rotate_down;
	bool			jump;
	bool			sneak;
	t_vecd			move;
}					t_keybinds;

#endif
