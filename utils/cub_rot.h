/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rot.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:37:08 by ttranche          #+#    #+#             */
/*   Updated: 2021/01/12 02:11:04 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ROT_H
# define CUB_ROT_H

# include <math.h>

typedef struct	s_rot
{
	double		angle;
	double		cos;
	double		sin;
}				t_rot;

t_rot			make_rot(double angle);

#endif
