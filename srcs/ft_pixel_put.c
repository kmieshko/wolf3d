/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:01:31 by kmieshko          #+#    #+#             */
/*   Updated: 2018/12/20 14:01:33 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_pixel_put(SDL_Surface *surface, int x, int y, int color)
{
	unsigned char	*pixels;
	int				r;
	int				g;
	int				b;

	pixels = (unsigned char*)surface->pixels;
	r = (color & 0xff);
	g = ((color >> 8) & 0xff);
	b = ((color >> 16) & 0xff);
	pixels[y * surface->pitch + 4 * x] = r;
	pixels[y * surface->pitch + 4 * x + 1] = g;
	pixels[y * surface->pitch + 4 * x + 2] = b;
}
