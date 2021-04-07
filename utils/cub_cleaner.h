/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cleaner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:51:51 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/24 11:23:46 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_CLEANER_H
# define CUB_CLEANER_H

# include "../cub.h"
# include "../sprites/cub_sprites.h"
# include "cub_line_reader.h"

void	destroy_img(t_vars *vars, t_img *img);
void	clean_images(t_vars *vars);
void	clean_all(t_vars *vars);
void	clean_and_exit(int code, t_vars *vars);
int		clean_and_exit_z(t_vars *vars);
int		mlx_destroy_display(void *mlx_ptr);

#endif
