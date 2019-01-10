/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:00:17 by kmieshko          #+#    #+#             */
/*   Updated: 2019/01/10 14:00:18 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	clear_buffer(int buffer[WIN_H][WIN_W])
{
	int i;
	int j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			buffer[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	dda_algorithm(t_wolf *wolf)
{
	wolf->intersect = 0;
	while (wolf->intersect == 0)
	{
		if (wolf->side_dist.x < wolf->side_dist.y)
		{
			wolf->side_dist.x += wolf->delta_dist.x;
			wolf->map.x += wolf->step.x;
			wolf->side = (wolf->ray_dir.x < 0) ? 0 : 2;
		}
		else
		{
			wolf->side_dist.y += wolf->delta_dist.y;
			wolf->map.y += wolf->step.y;
			wolf->side = (wolf->ray_dir.y < 0) ? 1 : 3;
		}
		if (wolf->map.data[wolf->map.x][wolf->map.y] > 0)
			wolf->intersect = 1;
	}
}

static void	loop(t_wolf *wolf, int buffer[WIN_H][WIN_W], int x)
{
	calc_ray_pos_and_dir(wolf, x);
	wolf->map.x = (int)wolf->start.x;
	wolf->map.y = (int)wolf->start.y;
	wolf->delta_dist.x = fabs(1 / wolf->ray_dir.x);
	wolf->delta_dist.y = fabs(1 / wolf->ray_dir.y);
	calc_step_and_init_side_dist(wolf);
	dda_algorithm(wolf);
	wolf->dist_to_wall = (wolf->side == 0 || wolf->side == 2) ?
	(wolf->map.x - wolf->start.x + (1 - wolf->step.x) / 2) / wolf->ray_dir.x :
	(wolf->map.y - wolf->start.y + (1 - wolf->step.y) / 2) / wolf->ray_dir.y;
	wolf->inten = wolf->weapon > 0 ?
	ft_clamp_with_param(1 - (wolf->dist_to_wall / sqrt(pow(wolf->map.rows, 2)
		+ pow(wolf->map.col, 2))), 0.1, 1) : 1;
	wolf->wall_height = (int)(WIN_H / wolf->dist_to_wall);
	if (wolf->wall_height == 0)
		wolf->wall_height = 1;
	calc_draw_limits(wolf);
	wolf->nb_text = wolf->map.data[wolf->map.x][wolf->map.y];
	calc_wall_hit(wolf);
	calc_x_coord_on_texture(wolf);
	fill_buffer_wall_colors(wolf, buffer, x);
	get_floor_coord(wolf);
	fill_buf_ceiling_floor(wolf, buffer, x);
	draw_weapon(wolf, buffer, x);
}

static void	loop_events(t_wolf *wolf, t_window *win)
{
	while (SDL_PollEvent(&win->e) != 0)
	{
		if (win->e.type == SDL_QUIT)
			win->quit = 1;
		if (win->e.type == SDL_KEYDOWN)
		{
			if (win->e.key.keysym.sym == SDLK_ESCAPE)
			{
				win->quit = 1;
				break ;
			}
			if (win->e.key.keysym.sym == SDLK_s)
				wolf->switcher *= -1;
			if (win->e.key.keysym.sym == SDLK_w)
				wolf->weapon *= -1;
			if (win->e.key.keysym.sym == SDLK_l)
				system("leaks wolf3d");
		}
	}
}

void		main_loop(t_window *win, t_wolf *wolf)
{
	int	x;
	int	buffer[WIN_H][WIN_W];

	while (!win->quit)
	{
		loop_events(wolf, win);
		x = -1;
		while (++x < WIN_W)
			loop(wolf, buffer, x);
		draw_buffer(win, buffer);
		clear_buffer(buffer);
		manage(win, wolf);
		SDL_UpdateWindowSurface(win->window);
	}
}
