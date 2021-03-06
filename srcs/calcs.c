/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:53:01 by kmieshko          #+#    #+#             */
/*   Updated: 2019/01/09 19:53:03 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	calc_ray_pos_and_dir(t_wolf *wolf, int x)
{
	wolf->cam.x = 2 * x / (double)WIN_W - 1;
	wolf->ray_dir.x = wolf->dir.x + wolf->plane.x * wolf->cam.x;
	wolf->ray_dir.y = wolf->dir.y + wolf->plane.y * wolf->cam.x;
}

void	calc_step_and_init_side_dist(t_wolf *wolf)
{
	if (wolf->ray_dir.x < 0)
	{
		wolf->step.x = -1;
		wolf->side_dist.x = (wolf->start.x - wolf->map.x) * wolf->delta_dist.x;
	}
	else
	{
		wolf->step.x = 1;
		wolf->side_dist.x = (wolf->map.x + 1.0 - wolf->start.x) *
			wolf->delta_dist.x;
	}
	if (wolf->ray_dir.y < 0)
	{
		wolf->step.y = -1;
		wolf->side_dist.y = (wolf->start.y - wolf->map.y) * wolf->delta_dist.y;
	}
	else
	{
		wolf->step.y = 1;
		wolf->side_dist.y = (wolf->map.y + 1.0 - wolf->start.y) *
			wolf->delta_dist.y;
	}
}

void	calc_draw_limits(t_wolf *wolf)
{
	wolf->draw_start = -wolf->wall_height / 2 + WIN_H / 2;
	if (wolf->draw_start < 0)
		wolf->draw_start = 0;
	wolf->draw_end = wolf->wall_height / 2 + WIN_H / 2;
	if (wolf->draw_end >= WIN_H)
		wolf->draw_end = WIN_H;
}

void	calc_wall_hit(t_wolf *wolf)
{
	if (wolf->side == 0 || wolf->side == 2)
		wolf->wall_hit = wolf->start.y + wolf->dist_to_wall * wolf->ray_dir.y;
	else
		wolf->wall_hit = wolf->start.x + wolf->dist_to_wall * wolf->ray_dir.x;
	wolf->wall_hit -= floor(wolf->wall_hit);
}

void	calc_x_coord_on_texture(t_wolf *wolf)
{
	wolf->text.x = (int)(wolf->wall_hit * (double)TEXT_W);
	if ((wolf->side == 0 || wolf->side == 2) && wolf->ray_dir.x > 0)
		wolf->text.x = TEXT_W - wolf->text.x - 1;
	if ((wolf->side == 1 || wolf->side == 3) && wolf->ray_dir.y < 0)
		wolf->text.x = TEXT_W - wolf->text.x - 1;
}
