/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cardinal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 21:22:36 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 12:25:18 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_CARDINAL_H
# define CUB_CARDINAL_H

# include "../render/cub_raycast.h"

t_cardinal	get_cardinal(t_trace trace);
t_cardinal	get_opposite(t_cardinal card);
t_vec		get_direction(t_cardinal card);

#endif
