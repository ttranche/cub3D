/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:34:12 by ttranche          #+#    #+#             */
/*   Updated: 2021/02/02 10:51:29 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_TEXTURE_H
# define CUB_TEXTURE_H

# include "../cub.h"
# include "../utils/cub_cleaner.h"

t_img	make_skybox(t_vars *vars, t_img *img, char *path);
t_img	make_gun(t_vars *vars, t_img *img, char *path);
t_img	make_dash(t_vars *vars, t_img *img, char *path);

#endif
