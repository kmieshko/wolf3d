/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_music.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:01:03 by kmieshko          #+#    #+#             */
/*   Updated: 2019/01/09 20:01:04 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_music(Mix_Music *music)
{
	if (Mix_Init(MIX_INIT_MP3) == -1)
		error((char *)Mix_GetError());
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
		error((char *)Mix_GetError());
	music = Mix_LoadMUS("1.mp3");
	if (music == NULL)
		error((char *)Mix_GetError());
	Mix_PlayMusic(music, -1);
}
