/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mouseover_struct.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:13:52 by ttranche          #+#    #+#             */
/*   Updated: 2021/01/31 14:14:25 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MOUSEOVER_STRUCT_H
# define CUB_MOUSEOVER_STRUCT_H

typedef struct		s_mouseover
{
	bool			found;
	t_vec			pos;
	t_cardinal		card;
}					t_mouseover;

#endif
