/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:07:28 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 14:31:23 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_sprite_list.h"

/*
** Swaps chained list pointers, used in the sprite_sort function
*/

void		swap_sprite(t_sprite **prevnext, t_sprite *last)
{
	t_sprite	*swap;

	swap = *prevnext;
	*prevnext = last->next;
	swap->next = last->next->next;
	(*prevnext)->next = swap;
}

/*
** Sorts the sprites by distance to the player
*/

void		sprite_sort(t_vars *vars, t_sprite **begin_list)
{
	t_sprite	*last;
	t_sprite	*prev;

	prev = NULL;
	last = *begin_list;
	while (last && last->next)
	{
		if (square_dist(vars->player.pos, last->pos) <
			square_dist(vars->player.pos, last->next->pos))
		{
			if (prev == NULL)
				swap_sprite(begin_list, last);
			else
				swap_sprite(&(prev->next), last);
			last = *begin_list;
			prev = NULL;
		}
		else
		{
			prev = last;
			last = last->next;
		}
	}
}

/*
** Creates a new sprite
*/

t_sprite	*make_sprite(t_vecd pos, t_sprite_k kind, t_img *img)
{
	t_sprite *elem;

	if (!(elem = malloc(sizeof(t_sprite))))
		return (NULL);
	elem->pos = pos;
	elem->kind = kind;
	elem->texture = img;
	elem->last_hurt = 0;
	elem->dead = false;
	elem->next = NULL;
	elem->path = NULL;
	elem->path_index = 0;
	return (elem);
}

/*
** Adds a new sprite to the begining of the list
*/

t_sprite	*sprite_pf(t_sprite **begin_list, t_vecd pos, t_sprite_k kind,
				t_img *img)
{
	t_sprite *first;

	if (!(first = make_sprite(pos, kind, img)))
		return (NULL);
	first->next = *begin_list;
	*begin_list = first;
	return (first);
}

/*
** Frees all the sprites in the list and sets it to null
*/

void		empty_sprites(t_sprite **begin_list)
{
	t_sprite *first;
	t_sprite *next;

	first = *begin_list;
	while (first)
	{
		next = first->next;
		free(first);
		first = next;
	}
	*begin_list = NULL;
}
