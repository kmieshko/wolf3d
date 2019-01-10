/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:56:56 by kmieshko          #+#    #+#             */
/*   Updated: 2019/01/09 19:56:57 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_structure_window(t_window *win, char *name)
{
	win->quit = 0;
	win->surface = NULL;
	win->window = NULL;
	win->window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, SDL_WINDOW_SHOWN);
	win->surface = SDL_GetWindowSurface(win->window);
}

void	init_structure_wolf(t_wolf *wolf)
{
	wolf->plane.x = 0.0f;
	wolf->plane.y = 0.66f;
	wolf->move_speed = 0.1f;
	wolf->rot_speed = 0.05;
	wolf->switcher = 1;
	wolf->weapon = -1;
	wolf->inten = 1;
	wolf->dir.x = -1;
	wolf->dir.y = 0;
}
