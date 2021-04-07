/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bitmap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:43:58 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 12:48:35 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BITMAP_H
# define CUB_BITMAP_H

# include "../cub.h"

t_bmp_partial_alligned_header	get_generic_header(int width, int height);
void							*bad_bzero(void *o, size_t len);
int								render_and_save(t_vars *vars);

#endif
