/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_portal_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:45:20 by ttranche          #+#    #+#             */
/*   Updated: 2021/01/10 23:01:14 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_portal_list.h"

t_portal_render	*make_portal_render(t_shape line, float offset)
{
	t_portal_render *elem;

	if (!(elem = malloc(sizeof(t_portal_render))))
		return (NULL);
	elem->line = line;
	elem->offset = offset;
	elem->next = NULL;
	return (elem);
}

void			portal_render_pf(t_portal_render **begin_list, t_shape line,
					float offset)
{
	t_portal_render *first;

	if (!(first = make_portal_render(line, offset)))
		return ;
	first->next = *begin_list;
	*begin_list = first;
}

void			portal_foreach_free(t_portal_render *begin_list,
					void (*f)(t_shape, float, t_vars*), t_vars *vars)
{
	t_portal_render *last;
	t_portal_render *next;

	last = begin_list;
	while (last)
	{
		f(last->line, last->offset, vars);
		next = last->next;
		free(last);
		last = next;
	}
}
