/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sound_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:46:06 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:03:38 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_sound_bonus.h"

void	init_sound_empty(t_sounds *sounds)
{
	sounds->door = 0;
	sounds->hurt = 0;
	sounds->stomp = 0;
	sounds->portal = 0;
	sounds->heal = 0;
	sounds->ambient = 0;
	sounds->walk = 0;
}

void	clear_sounds(t_sounds *sounds)
{
	if (sounds->door)
		BASS_StreamFree(sounds->door);
	if (sounds->hurt)
		BASS_StreamFree(sounds->hurt);
	if (sounds->stomp)
		BASS_StreamFree(sounds->stomp);
	if (sounds->portal)
		BASS_StreamFree(sounds->portal);
	if (sounds->heal)
		BASS_StreamFree(sounds->heal);
	if (sounds->ambient)
		BASS_StreamFree(sounds->ambient);
	if (sounds->walk)
		BASS_StreamFree(sounds->walk);
	BASS_Free();
}

bool	load_sound(uint32_t *s, char *path)
{
	static bool loaded;

	loaded |= BASS_Init(-1, 48000, 0, 0, 0);
	if (!loaded || *s)
		return (false);
	*s = BASS_StreamCreateFile(false, path, 0, 0, 0);
	return (true);
}

void	play_sound_alt(uint32_t s, bool play, bool loop)
{
	if (!s)
		return ;
	if (loop)
		BASS_ChannelFlags(s,
			BASS_SAMPLE_LOOP, BASS_SAMPLE_LOOP);
	if (play)
		BASS_ChannelPlay(s, 0);
	else
		BASS_ChannelPause(s);
}

void	play_sound(uint32_t s)
{
	if (!s)
		return ;
	BASS_ChannelStop(s);
	BASS_ChannelSetPosition(s, 0, 0);
	BASS_ChannelPlay(s, 0);
}
