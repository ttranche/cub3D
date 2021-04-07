/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:07:28 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 11:54:46 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SPRITE_LIST_H
# define CUB_SPRITE_LIST_H

# include "../cub.h"

void		swap_sprite(t_sprite **prevnext, t_sprite *last);
void		sprite_sort(t_vars *vars, t_sprite **begin_list);
t_sprite	*make_sprite(t_vecd pos, t_sprite_k kind, t_img *img);
t_sprite	*sprite_pf(t_sprite **begin_list, t_vecd pos,
				t_sprite_k kind, t_img *img);
void		empty_sprites(t_sprite **begin_list);

#endif
