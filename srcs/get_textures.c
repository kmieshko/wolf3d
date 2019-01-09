/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:17:29 by kmieshko          #+#    #+#             */
/*   Updated: 2018/12/20 14:17:32 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	copy_memory(t_wolf *w, int index, SDL_Surface *s)
{
	if (index == 1)
		ft_memcpy(&w->textures.a, s->pixels, sizeof(int) * TS);
	else if (index == 2)
		ft_memcpy(&w->textures.b, s->pixels, sizeof(int) * TS);
	else if (index == 3)
		ft_memcpy(&w->textures.c, s->pixels, sizeof(int) * TS);
	else if (index == 4)
		ft_memcpy(&w->textures.d, s->pixels, sizeof(int) * TS);
	else if (index == 5)
		ft_memcpy(&w->textures.e, s->pixels, sizeof(int) * TS);
	else if (index == 6)
		ft_memcpy(&w->textures.f, s->pixels, sizeof(int) * TS);
}

static void	load_texture(char *path, t_wolf *w, int index)
{
	SDL_Surface		*s;

	s = IMG_Load(path);
	if (!s)
	{
		if (index == 1)
			ft_memset(&w->textures.a, 0, sizeof(int) * TS);
		else if (index == 2)
			ft_memset(&w->textures.b, 0, sizeof(int) * TS);
		else if (index == 3)
			ft_memset(&w->textures.c, 0, sizeof(int) * TS);
		else if (index == 4)
			ft_memset(&w->textures.d, 0, sizeof(int) * TS);
		else if (index == 5)
			ft_memset(&w->textures.e, 0, sizeof(int) * TS);
		else if (index == 6)
			ft_memset(&w->textures.f, 0, sizeof(int) * TS);
		error((char *)IMG_GetError());
	}
	else
		copy_memory(w, index, s);
	SDL_FreeSurface(s);
}

static void	get_weapon_texture(t_wolf *wolf)
{
	SDL_Surface		*s;

	s = IMG_Load("images/weapon.png");
	if (!s)
	{
		ft_memset(wolf->textures.w, 0, sizeof(int) * WS);
		error((char *)IMG_GetError());
	}
	else
		ft_memcpy(wolf->textures.w, s->pixels, sizeof(int) * WS);
	SDL_FreeSurface(s);
}

void		get_textures(t_wolf *wolf)
{
	int index;

	index = 1;
	get_weapon_texture(wolf);
	while (index <= NB_TEXT)
	{
		if (index == 1)
			load_texture("images/1.jpg", wolf, index);
		else if (index == 2)
			load_texture("images/2.jpg", wolf, index);
		else if (index == 3)
			load_texture("images/3.jpg", wolf, index);
		else if (index == 4)
			load_texture("images/4.jpg", wolf, index);
		else if (index == 5)
			load_texture("images/5.jpg", wolf, index);
		else if (index == 6)
			load_texture("images/6.jpg", wolf, index);
		index++;
	}
}
