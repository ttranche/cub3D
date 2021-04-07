/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_portal_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:10:57 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:25:58 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PORTAL_STRUCT_H
# define CUB_PORTAL_STRUCT_H

typedef struct				s_portal_render
{
	t_shape					line;
	float					offset;
	struct s_portal_render	*next;
}							t_portal_render;

typedef struct				s_portal
{
	t_vec					pos;
	t_cardinal				card;
	struct s_portal			*link;
}							t_portal;

#endif
