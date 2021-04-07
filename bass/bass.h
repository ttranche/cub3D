/*
	BASS 2.4 C/C++ header file
	Copyright (c) 1999-2019 Un4seen Developments Ltd.

	See the BASS.CHM file for more detailed documentation
*/

#ifndef BASS_H
# define BASS_H

bool		BASS_Free();
bool		BASS_Init(int device, uint32_t freq, uint32_t flags, void *win,
				void *dsguid);
bool		BASS_StreamFree(uint32_t handle);
bool		BASS_ChannelPlay(uint32_t handle, bool restart);
bool		BASS_ChannelStop(uint32_t handle);
uint32_t	BASS_ChannelFlags(uint32_t handle, uint32_t flags, uint32_t mask);
bool		BASS_ChannelSetPosition(uint32_t handle, uint64_t pos,
				uint32_t mode);
uint32_t	BASS_StreamCreateFile(bool mem, const void *file, uint64_t offset,
				uint64_t length, uint32_t flags);
bool		BASS_ChannelPause(uint32_t handle);

#endif
