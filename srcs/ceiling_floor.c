/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:04:35 by kmieshko          #+#    #+#             */
/*   Updated: 2019/01/09 20:04:36 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_floor_coord(t_wolf *wolf)
{
	if ((wolf->side == 0 || wolf->side == 2) && wolf->ray_dir.x > 0)
	{
		wolf->floor.x = wolf->map.x;
		wolf->floor.y = wolf->map.y + wolf->wall_hit;
	}
	else if ((wolf->side == 0 || wolf->side == 2) && wolf->ray_dir.x < 0)
	{
		wolf->floor.x = wolf->map.x + 1.0f;
		wolf->floor.y = wolf->map.y + wolf->wall_hit;
	}
	else if ((wolf->side == 1 || wolf->side == 3) && wolf->ray_dir.y > 0)
	{
		wolf->floor.x = wolf->map.x + wolf->wall_hit;
		wolf->floor.y = wolf->map.y;
	}
	else if ((wolf->side == 1 || wolf->side == 3) && wolf->ray_dir.y < 0)
	{
		wolf->floor.x = wolf->map.x + wolf->wall_hit;
		wolf->floor.y = wolf->map.y + 1.0f;
	}
}

void	fill_buf_ceiling_floor(t_wolf *wolf, int buffer[WIN_H][WIN_W], int x)
{
	int					y;
	double				koef;
	t_constit			floor_text;
	t_double_constit	cur_floor;

	if (wolf->draw_end < 0)
		wolf->draw_end = WIN_H;
	y = wolf->draw_end;
	while (++y < WIN_H)
	{
		wolf->cur_dist = WIN_H / (2.0 * y - WIN_H);
		koef = wolf->cur_dist / wolf->dist_to_wall;
		cur_floor.x = koef * wolf->floor.x + (1.0 - koef) * wolf->start.x;
		cur_floor.y = koef * wolf->floor.y + (1.0 - koef) * wolf->start.y;
		floor_text.x = (int)(cur_floor.x * TEXT_W) % TEXT_W;
		floor_text.y = (int)(cur_floor.y * TEXT_H) % TEXT_H;
		wolf->inten = wolf->weapon > 0 ?
			ft_clamp_with_param((0.5 * y) / (WIN_H - y), 0.1, 1) : 1;
		wolf->color = (wolf->textures.a[TEXT_H * floor_text.y +
			floor_text.x] >> 1) & 8355711;
		buffer[y - 1][x] = get_color(wolf->color, wolf->inten);
		wolf->color = (wolf->textures.c[TEXT_H * floor_text.y +
			floor_text.x] >> 1) & 8355711;
		buffer[WIN_H - y][x] = get_color(wolf->color, wolf->inten);
	}
}
