/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:39:42 by ttranche          #+#    #+#             */
/*   Updated: 2021/01/30 14:13:45 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SETTER_H
# define CUB_SETTER_H

# include "../cub.h"
# include "../utils/cub_error.h"

void	set_resolution(t_vars *vars, char *input);
void	set_texture(t_img *img, t_vars *vars, char *path);
void	set_color(t_vars *vars, int *val, char *input);
void	set_sound(uint32_t *s, t_vars *vars, char *path);

#endif
