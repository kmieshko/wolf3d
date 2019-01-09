/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:58:21 by kmieshko          #+#    #+#             */
/*   Updated: 2019/01/09 19:58:24 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	choose_wall_color(t_wolf *wolf)
{
	if (wolf->nb_text == 1)
		wolf->color = wolf->textures.a[TEXT_H * wolf->text.y + wolf->text.x];
	else if (wolf->nb_text == 2)
		wolf->color = wolf->textures.b[TEXT_H * wolf->text.y + wolf->text.x];
	else if (wolf->nb_text == 3)
		wolf->color = wolf->textures.c[TEXT_H * wolf->text.y + wolf->text.x];
	else if (wolf->nb_text == 4)
		wolf->color = wolf->textures.d[TEXT_H * wolf->text.y + wolf->text.x];
	else if (wolf->nb_text == 5)
		wolf->color = wolf->textures.e[TEXT_H * wolf->text.y + wolf->text.x];
	else if (wolf->nb_text == 6)
		wolf->color = wolf->textures.f[TEXT_H * wolf->text.y + wolf->text.x];
	if (wolf->side == 1 || wolf->side == 3)
		wolf->color = (wolf->color >> 1) & 8355711;
}

void	fill_buffer_wall_colors(t_wolf *w, int buffer[WIN_H][WIN_W], int x)
{
	int		y;
	int		d;

	y = w->draw_start;
	while (y < w->draw_end)
	{
		d = y * 256 - WIN_H * 128 + w->wall_height * 128;
		w->text.y = ((d * TEXT_H) / w->wall_height) / 256;
		if (w->switcher > 0)
		{
			if (w->side == 0)
				w->color = w->textures.a[TEXT_H * w->text.y + w->text.x];
			else if (w->side == 1)
				w->color = w->textures.b[TEXT_H * w->text.y + w->text.x];
			else if (w->side == 2)
				w->color = w->textures.c[TEXT_H * w->text.y + w->text.x];
			else if (w->side == 3)
				w->color = w->textures.d[TEXT_H * w->text.y + w->text.x];
		}
		else
			choose_wall_color(w);
		w->color = get_color(w->color, w->inten);
		buffer[y][x] = w->color;
		y++;
	}
}
