/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:48:04 by kmieshko          #+#    #+#             */
/*   Updated: 2019/01/10 13:48:05 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	free_all(t_window *win)
{
	SDL_FreeSurface(win->surface);
	SDL_DestroyWindow(win->window);
	win->surface = NULL;
	win->window = NULL;
	SDL_Quit();
}
