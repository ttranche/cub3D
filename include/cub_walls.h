/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_walls.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:17:25 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:26:29 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_WALLS_H
# define CUB_WALLS_H

typedef struct		s_walls {
	t_img			north;
	t_img			south;
	t_img			east;
	t_img			west;
}					t_walls;

#endif
