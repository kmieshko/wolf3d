/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:03:03 by kmieshko          #+#    #+#             */
/*   Updated: 2019/01/09 20:03:05 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_buffer(t_window *win, int buffer[WIN_H][WIN_W])
{
	int i;
	int j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			ft_pixel_put(win->surface, j, i, buffer[i][j]);
			j++;
		}
		i++;
	}
}

void	draw_weapon(t_wolf *wolf, int buffer[WIN_H][WIN_W], int x)
{
	int k;
	int	y;

	k = 0;
	if (wolf->weapon > 0)
	{
		y = WIN_H - TEXT_H / 2;
		while (y < WIN_H && (x > WIN_W / 2 - WEAPON_H / 2 / 2 &&
			x < WIN_W / 2 + WEAPON_H / 2 / 2))
		{
			wolf->w_color = wolf->textures.w[WEAPON_H * k + x -
				(WIN_W / 2 - WEAPON_H / 2)];
			if (wolf->w_color != BLACK && wolf->w_color != WHITE)
				buffer[y][x] = wolf->w_color;
			y++;
			k++;
		}
	}
}
